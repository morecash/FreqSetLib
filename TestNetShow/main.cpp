#include "testnetshow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestNetShow w;
	w.show();
	return a.exec();
}
