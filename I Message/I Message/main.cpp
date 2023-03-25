#include "IMessage.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	IMessage w;
	w.setFixedSize(425, 305);
	w.show();
	return a.exec();
}
