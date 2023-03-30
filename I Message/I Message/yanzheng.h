#pragma once

#include <QWidget>
#include "ui_yanzheng.h"

QT_BEGIN_NAMESPACE
namespace Ui { class yanzhengClass; };
QT_END_NAMESPACE

class YanZheng : public QWidget
{
	Q_OBJECT

public:
	YanZheng(const int& cfd, QString from, QString username, QWidget* parent = nullptr);
	~YanZheng();

	void init(QString name, QString account);
	void faSong();
	void guanBi();

private:
	Ui::yanzhengClass* ui;

	int cfd;
	QString from;
	QString account;
	QString username;
};
