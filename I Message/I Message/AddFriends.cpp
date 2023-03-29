#include <WinSock2.h>
#include <WS2tcpip.h>

#include "AddFriends.h"

AddFriends::AddFriends(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::AddFriendsClass())
{
	ui->setupUi(this);

	model = new QStandardItemModel;
	model->setColumnCount(2);
	model->setHeaderData(0, Qt::Horizontal, "账号");
	model->setHeaderData(1, Qt::Horizontal, "昵称");
	ui->tableView->setModel(model);
	ui->tableView->setColumnWidth(0, 330);
	ui->tableView->setColumnWidth(0, 330);

	connect(ui->chazhaobutton, &QPushButton::clicked, this, &AddFriends::showFriends);
}

AddFriends::~AddFriends()
{
	delete ui;
}

void AddFriends::showFriends()
{
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(cfd >= 0);
	sockaddr_in caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.10.150", &caddr.sin_addr.S_un.S_addr);
	int ret = ::connect(cfd, (sockaddr*)&caddr, sizeof(caddr));
	assert(ret == 0);
	char account[50];
	char name[50];
	sprintf(account, "chazhao:");
	sprintf(account + strlen(account), ui->chazhao->text().toStdString().c_str());
	send(cfd, account, sizeof(account), NULL);
	recv(cfd, name, sizeof(name), NULL);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setModel(model);
	if(name != " ")
	{
		model->setItem(0, 0, new QStandardItem(ui->chazhao->text()));
		model->setItem(0, 1, new QStandardItem(name));
	}
	else
		model->setItem(0, 0, new QStandardItem("不存在该用户"));
}
