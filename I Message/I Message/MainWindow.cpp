#include <QMouseEvent>

#include "MainWindow.h"
#include "AddFriends.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindowClass())
{
	ui->setupUi(this);

	connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setName(const std::string& s)
{
	ui->name->setText(QString(s.c_str()));
}

void MainWindow::add()
{
	AddFriends* a = new AddFriends;
	a->setWindowModality(Qt::ApplicationModal);
	a->show();
}
