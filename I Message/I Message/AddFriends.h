#pragma once

#include <QWidget>
#include <qstandarditemmodel.h>
#include "ui_AddFriends.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddFriendsClass; };
QT_END_NAMESPACE

class AddFriends : public QWidget
{
	Q_OBJECT

public:
	AddFriends(const int& cfd, QString username, QWidget* parent = nullptr);
	~AddFriends();

	void showFriends();
	void addFriends();
	void init(QString f);
private:
	Ui::AddFriendsClass* ui;
	QStandardItemModel* model;

	int cfd;
	QString from;
	QString username;
};
