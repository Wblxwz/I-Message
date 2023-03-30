#include <WinSock2.h>
#include <iostream>

#include "MainWindow.h"
#include "AddFriends.h"
#include "XinShenQing.h"

MainWindow::MainWindow(const int& cfd, QWidget* parent)
	: QMainWindow(parent), cfd(cfd), username("")
	, ui(new Ui::MainWindowClass())
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

	ui->lianxiren->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->lianxiren->setModel(model);

	connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
	connect(ui->xinhaoyou, &QPushButton::clicked, this, &MainWindow::xinShenQing);
}

MainWindow::~MainWindow()
{
	char buf[5];
	sprintf(buf, "out");
	send(cfd, buf, sizeof(buf), NULL);
	closesocket(cfd);
	delete ui;
}

void MainWindow::setName(const std::string& s, const char* f)
{
	ui->name->setText(QString(s.c_str()));
	ui->bian->setText(f);
	username = s.c_str();
}

void MainWindow::setNewFriends(const char* s)
{
	QString ss(s);
	ui->xinhaoyou->setText(ss);
}

void MainWindow::add()
{
	AddFriends* a = new AddFriends(cfd, username);
	a->init(ui->bian->text());
	a->setWindowModality(Qt::ApplicationModal);
	a->show();
}

void MainWindow::xinShenQing()
{
	XinShenQing* x = new XinShenQing(cfd, infos);
	x->setWindowModality(Qt::ApplicationModal);
	x->show();
}

void MainWindow::setInfos(std::vector<info*> infos)
{
	this->infos = infos;
}

void MainWindow::addPeople(QString account, QString name)
{
	QString s = name;
	s.append(account);
	int n = model->rowCount();
	model->setItem(n, new QStandardItem(s));
}
