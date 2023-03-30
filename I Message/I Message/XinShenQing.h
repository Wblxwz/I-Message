#pragma once

#include <QMainWindow>
#include <qstandarditemmodel.h>

#include "IMessage.h"
#include "ui_XinShenQing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class XinShenQingClass; };
QT_END_NAMESPACE

class XinShenQing : public QMainWindow
{
	Q_OBJECT

public:
	XinShenQing(const int& cfd,std::vector<info*> infos,QWidget *parent = nullptr);
	~XinShenQing();

	void tongYi();
	void juJue();
private:
	Ui::XinShenQingClass *ui;

	QStandardItemModel* model;
	std::vector<info*> infos;

	int cfd;
};
