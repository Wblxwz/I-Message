﻿#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <QtWidgets/QMainWindow>
#include "ui_IMessage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IMessageClass; };
QT_END_NAMESPACE

struct info
{
	info() :from(""), yanzheng(""), name("") {}
	QString from;
	QString yanzheng;
	QString name;
};

class IMessage : public QMainWindow
{
	Q_OBJECT

public:
	IMessage(QWidget* parent = nullptr);
	void init();
	void signUp();
	void signUpToServer();
	void logIn();
	const int getNewCfd();
	~IMessage();
private:
	Ui::IMessageClass* ui;
	int cfd;

	std::vector<info*> infos;
};
