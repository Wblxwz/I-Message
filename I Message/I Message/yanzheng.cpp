#include <WinSock2.h>

#include "yanzheng.h"

YanZheng::YanZheng(const int& cfd, QString from, QString username, QWidget* parent)
	: QWidget(parent), cfd(cfd), from(from), username(username), account("")
	, ui(new Ui::yanzhengClass())
{
	ui->setupUi(this);

	connect(ui->fasong, &QPushButton::clicked, this, &YanZheng::faSong);
	connect(ui->guanbi, &QPushButton::clicked, this, &YanZheng::guanBi);
}

YanZheng::~YanZheng()
{
	delete ui;
}

void YanZheng::init(QString name, QString account)
{
	this->account = account;
	ui->name->setText(name);
	ui->account->setText(account);
}

void YanZheng::faSong()
{
	char buf[200];
	sprintf(buf, "from:");
	sprintf(buf + strlen(buf), from.toStdString().c_str());
	sprintf(buf + strlen(buf), "user:");
	sprintf(buf + strlen(buf), username.toStdString().c_str());
	sprintf(buf + strlen(buf), "to:");
	sprintf(buf + strlen(buf), account.toStdString().c_str());
	sprintf(buf + strlen(buf), "yanzheng:");	
	sprintf(buf + strlen(buf), ui->yanzheng->toPlainText().toStdString().c_str());

	send(cfd, buf, sizeof(buf), NULL);
	this->close();
}

void YanZheng::guanBi()
{
	this->close();
}
