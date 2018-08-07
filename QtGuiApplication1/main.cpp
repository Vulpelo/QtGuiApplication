#include <QtWidgets/QApplication>

#include "QtGuiApplication1.h"
#include "Controler.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	QtGuiApplication1 w;
	Controler controler(&w);
	w.show();
	w.Execute(&controler);
	return a.exec();
}
