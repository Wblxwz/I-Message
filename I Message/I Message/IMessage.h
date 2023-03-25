#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IMessage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IMessageClass; };
QT_END_NAMESPACE

class IMessage : public QMainWindow
{
	Q_OBJECT

public:
	IMessage(QWidget* parent = nullptr);
	void init();
	void signUp();
	~IMessage();
private:
	Ui::IMessageClass* ui;
};
