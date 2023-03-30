#pragma once

#include <QMainWindow>
#include <qstandarditemmodel.h>

#include "IMessage.h"
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(const int& cfd, QWidget* parent = nullptr);
	~MainWindow();

	void setName(const std::string& s,const char* f);
	void setNewFriends(const char* s);
	void add();
	void xinShenQing();
	void setInfos(std::vector<info*> infos);
	void addPeople(QString account,QString name);
	void deletePeople(QString account);
private:
	Ui::MainWindowClass* ui;
	int cfd;
	QString username;
	std::vector<info*> infos;
	QStandardItemModel* model;
};
