#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QtGuiApplication1::Execute(ICon *ncontroler)
{
	controler = ncontroler;
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(doCommendFun()));
}