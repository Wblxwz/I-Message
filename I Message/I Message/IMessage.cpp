#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <regex>
#include <qmessagebox.h>
#include <qsettings.h>
#include <qfile.h>

#include "IMessage.h"
#include "MainWindow.h"

IMessage::IMessage(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::IMessageClass())
{
	ui->setupUi(this);
	init();
}

void IMessage::init()
{
	WSADATA wsadata;
	assert(WSAStartup(MAKEWORD(2, 2), &wsadata) == 0);
	cfd = getNewCfd();

	ui->account->setEditable(true);
	QFile file("C:\\IMessage\\IMessage.txt");
	QStringList lists;
	if (file.open(QFile::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString s = in.readLine();
			lists << s;
		}
	}
	ui->account->addItems(lists);
	QSettings* settings = new QSettings("C:\\IMessage\\IMessage.ini", QSettings::IniFormat);
	QString s = settings->value("ini/zidong").toString();
	if (s == "true")
	{
		ui->zidong->setChecked(true);
		//logIn();
	}
	s = settings->value("ini/jizhu").toString();
	if (s == "true")
	{
		ui->jizhu->setChecked(true);
		s = "account/";
		s.append(ui->account->lineEdit()->text());
		s = settings->value(s).toString();
		ui->pwd->setText(s);
	}

	ui->account->setPlaceholderText("账号");
	ui->pwd->setPlaceholderText("密码");
	ui->name->setPlaceholderText("昵称");
	ui->password->setPlaceholderText("密码");

	ui->zhaohui->setFlat(true);
	ui->zhuce->setFlat(true);
	ui->lijizhuce->setFlat(true);

	ui->nametishi->setHidden(true);
	ui->pwdtishi->setHidden(true);
	ui->tishi->setHidden(true);

	connect(ui->zidong, &QCheckBox::stateChanged, this, [&]() {
		if (ui->zidong->isChecked())
			ui->jizhu->setChecked(true);
		else
			ui->jizhu->setChecked(false);
		});
	connect(ui->zhuce, &QPushButton::clicked, this, [&]() {
		ui->stackedWidget->setCurrentIndex(1);
		});
	connect(ui->lijizhuce, &QPushButton::clicked, this, &IMessage::signUp);
	connect(ui->denglu, &QPushButton::clicked, this, &IMessage::logIn);
}

void IMessage::signUp()
{
	if (ui->queren->isChecked())
		ui->tishi->setHidden(true);
	else
		ui->tishi->setHidden(false);
	if (ui->name->text().isEmpty())
		ui->nametishi->setHidden(false);
	else
		ui->nametishi->setHidden(true);
	if (ui->password->text().isEmpty())
	{
		ui->pwdtishi->setText("密码不能为空");
		ui->pwdtishi->setHidden(false);
	}
	else
		ui->pwdtishi->setHidden(true);
	std::regex rpwd("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,16}$");
	bool ret = std::regex_match(ui->password->text().toStdString(), rpwd);
	if (!ret)
	{
		ui->pwdtishi->setText("密码应为数字和字母的组合，且长度为8-16位");
		ui->pwdtishi->setHidden(false);
	}
	else
		ui->pwdtishi->setHidden(true);
	if (ui->queren->isChecked() && !ui->password->text().isEmpty() && !ui->name->text().isEmpty() && ret)
	{
		signUpToServer();
		ui->name->setText("");
		ui->password->setText("");
		ui->queren->setChecked(false);
		ui->stackedWidget->setCurrentIndex(0);
	}
}

void IMessage::signUpToServer()
{
	//int cfd = getNewCfd();
	char buf[100]{ '0' };
	sprintf(buf, "name:");
	sprintf(buf + strlen(buf), ui->name->text().toStdString().c_str());
	sprintf(buf + strlen(buf), "pwd:");
	sprintf(buf + strlen(buf), ui->password->text().toStdString().c_str());
	send(cfd, buf, sizeof(buf), NULL);
	char tbuf[100]{ '0' };
	recv(cfd, tbuf, sizeof(tbuf), NULL);
	QString ss = "账号：";
	ss += tbuf;
	QMessageBox::information(this, "注册成功", ss);
	ui->account->lineEdit()->setText(tbuf);
	//closesocket(cfd);
}

void IMessage::logIn()
{
	ui->denglu->setText("登录中...");
	//int cfd = getNewCfd();
	char buf[100]{ '0' };
	sprintf(buf, "account:");
	sprintf(buf + strlen(buf), ui->account->lineEdit()->text().toStdString().c_str());
	sprintf(buf + strlen(buf), "pwd:");
	sprintf(buf + strlen(buf), ui->pwd->text().toStdString().c_str());
	send(cfd, buf, sizeof(buf), NULL);
	recv(cfd, buf, sizeof(buf), NULL);
	std::string s(buf);
	if (s == "true")
	{
		QSettings* settings = new QSettings("C:\\IMessage\\IMessage.ini", QSettings::IniFormat);
		if (ui->zidong->isChecked())
			settings->setValue("ini/zidong", "true");
		else
			settings->setValue("ini/zidong", "false");
		if (ui->jizhu->isChecked())
		{
			QSettings* settings = new QSettings("C:\\IMessage\\IMessage.ini", QSettings::IniFormat);
			settings->setValue("ini/jizhu", "true");
			QString s = "account/";
			s.append(ui->account->lineEdit()->text());
			settings->setValue(s, ui->pwd->text());
		}
		else
			settings->setValue("ini/jizhu", "false");
		bool isStored = true;
		QFile file("C:\\IMessage\\IMessage.txt");
		if (file.open(QFile::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);
			while (!in.atEnd())
			{
				QString s = in.readLine();
				if (s == ui->account->lineEdit()->text())
				{
					isStored = false;
					break;
				}
			}
		}
		QFile file1("C:\\IMessage\\IMessage.txt");
		if (isStored && file1.open(QFile::WriteOnly | QFile::Append))
		{
			QTextStream out(&file1);
			out << ui->account->lineEdit()->text() << "\n";
		}
		this->close();
		MainWindow* m = new MainWindow(cfd);
		char tbuf[200]{ '0' };
		sprintf(tbuf, "log:");
		sprintf(tbuf + strlen(tbuf), ui->account->lineEdit()->text().toStdString().c_str());
		send(cfd, tbuf, sizeof(tbuf), NULL);
		recv(cfd, tbuf, sizeof(tbuf), NULL);
		m->setName(std::string(tbuf),ui->account->lineEdit()->text().toStdString().c_str());
		m->show();
		std::string tn;
		char ttbuf[200];
		recv(cfd, ttbuf, sizeof(ttbuf), NULL);
		std::string ss(ttbuf), length = "新好友(";
		for (int i = 2; i < ss.size(); ++i)
		{
			length.push_back(ss[i]);
			tn.push_back(ss[i]);
		}
		length.push_back(')');
		m->setNewFriends(length.c_str());
		int size = atoi(tn.c_str());
		for (int i = 0; i < size; ++i)
		{
			char nbuf[200];
			recv(cfd, nbuf, sizeof(nbuf), NULL);
			std::string sss(nbuf);
			std::string from, name, yanzheng;
			int fn = sss.find("name:");
			for (int j = 5; j < fn; ++j)
				from.push_back(sss[j]);
			int fin = sss.find("info:");
			for (int j = fn + 5; j < fin; ++j)
				name.push_back(sss[j]);
			for (int j = fin + 5; j < sss.size(); ++j)
				yanzheng.push_back(sss[j]);

			info* in = new info;
			in->from = from.c_str();
			in->name = name.c_str();
			in->yanzheng = yanzheng.c_str();
			infos.push_back(in);
		}
		m->setInfos(infos);
	}
	else
		QMessageBox::critical(this, "错误", "账号不存在或密码错误");
	//closesocket(cfd);
}

const int IMessage::getNewCfd()
{
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(cfd >= 0);
	sockaddr_in caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.10.150", &caddr.sin_addr.S_un.S_addr);
	int ret = ::connect(cfd, (sockaddr*)&caddr, sizeof(caddr));
	assert(ret == 0);
	return cfd;
}

IMessage::~IMessage()
{
	delete ui;
}
