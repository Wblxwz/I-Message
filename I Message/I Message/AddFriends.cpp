#include <WinSock2.h>
#include <WS2tcpip.h>

#include "AddFriends.h"
#include "yanzheng.h"

AddFriends::AddFriends(const int& cfd, QString username, QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::AddFriendsClass()), cfd(cfd), username(username),from("")
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
	connect(ui->tableView, &QTableView::doubleClicked, this, &AddFriends::addFriends);
}

AddFriends::~AddFriends()
{
	delete ui;
}

void AddFriends::showFriends()
{
	char account[50];
	char name[50];
	sprintf(account, "chazhao:");
	sprintf(account + strlen(account), ui->chazhao->text().toStdString().c_str());
	send(cfd, account, sizeof(account), NULL);
	recv(cfd, name, sizeof(name), NULL);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setModel(model);
	if (name != " ")
	{
		model->setItem(0, 0, new QStandardItem(ui->chazhao->text()));
		model->setItem(0, 1, new QStandardItem(name));
	}
	else
		model->setItem(0, 0, new QStandardItem("不存在该用户"));
}

void AddFriends::addFriends()
{
	YanZheng* y = new YanZheng(cfd, from, username);
	y->setWindowModality(Qt::ApplicationModal);
	int row = ui->tableView->currentIndex().row();
	QModelIndex index1 = model->index(row, 0);
	QModelIndex index2 = model->index(row, 1);
	y->init(model->data(index2).toString(), model->data(index1).toString());
	y->show();
}

void AddFriends::init(QString f)
{
	this->from = f;
}
