#include "freqset.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FreqSet w;
	w.show();
	return a.exec();
}
