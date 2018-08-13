#include <QtWidgets/QApplication>

#include "SimpleCommandWriter.h"
#include "Controler.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SimpleCommandWriter w;
	Controler controler(&w);
	w.show();
	w.Execute(&controler);
	return a.exec();
}
