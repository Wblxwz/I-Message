#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#include "IMessage.h"

IMessage::IMessage(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::IMessageClass())
{
	ui->setupUi(this);
	init();
}

void IMessage::init()
{
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
		ui->pwdtishi->setHidden(false);
	else
		ui->pwdtishi->setHidden(true);
	if (ui->queren->isChecked() && !ui->password->text().isEmpty() && !ui->name->text().isEmpty())
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
	WSADATA wsadata;
	assert(WSAStartup(MAKEWORD(2, 2), &wsadata) == 0);
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(cfd >= 0);
	sockaddr_in caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.10.150", &caddr.sin_addr.S_un.S_addr);
	int ret = ::connect(cfd, (sockaddr*)&caddr, sizeof(caddr));
	char buf[1024]{ '0' };
	sprintf(buf, "name:");
	sprintf(buf + strlen(buf), ui->name->text().toStdString().c_str());
	sprintf(buf + strlen(buf), "pwd:");
	sprintf(buf + strlen(buf), ui->password->text().toStdString().c_str());
	send(cfd, buf, sizeof(buf), NULL);
	recv(cfd, buf, sizeof(buf), NULL);
	qDebug() << buf;
	closesocket(cfd);
}

IMessage::~IMessage()
{
	delete ui;
}
