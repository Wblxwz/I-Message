#include <qstandarditemmodel.h>
#include <WinSock2.h>

#include "XinShenQing.h"

XinShenQing::XinShenQing(const int& cfd, std::vector<info*> infos, QWidget* parent)
	: QMainWindow(parent), infos(infos), cfd(cfd)
	, ui(new Ui::XinShenQingClass())
{
	ui->setupUi(this);

	model = new QStandardItemModel;
	model->setColumnCount(3);
	model->setHeaderData(0, Qt::Horizontal, "账号");
	model->setHeaderData(1, Qt::Horizontal, "昵称");
	model->setHeaderData(2, Qt::Horizontal, "备注");
	ui->tableView->setModel(model);
	ui->tableView->setColumnWidth(0, 50);
	ui->tableView->setColumnWidth(1, 100);
	ui->tableView->setColumnWidth(2, 300);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	for (int i = 0; i < infos.size(); ++i)
	{
		model->setItem(i, 0, new QStandardItem(infos[i]->from));
		model->setItem(i, 1, new QStandardItem(infos[i]->name));
		model->setItem(i, 2, new QStandardItem(infos[i]->yanzheng));
	}

	connect(ui->tongyi, &QPushButton::clicked, this, &XinShenQing::tongYi);
	connect(ui->jujue, &QPushButton::clicked, this, &XinShenQing::juJue);
}

XinShenQing::~XinShenQing()
{
	delete ui;
}

void XinShenQing::tongYi()
{
	char buf[10];
	sprintf(buf, "tongyi");
	int n = ui->tableView->currentIndex().row();
	std::string c = std::to_string(n);
	sprintf(buf + strlen(buf), c.c_str());
	send(cfd, buf, sizeof(buf), NULL);
	this->close();
}

void XinShenQing::juJue()
{
	char buf[10];
	sprintf(buf, "jujue");
	int n = ui->tableView->currentIndex().row();
	std::string c = std::to_string(n);
	sprintf(buf + strlen(buf), c.c_str());
	send(cfd, buf, sizeof(buf), NULL);
	this->close();
}
