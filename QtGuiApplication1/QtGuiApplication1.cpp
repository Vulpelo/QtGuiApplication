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

string QtGuiApplication1::getCommendText() {
	// setting last written command
	ui.TextCtrlLastCommand->setText(ui.textBoxCommand->text());
	// returning written command
	return ui.textBoxCommand->text().toStdString();
}

void QtGuiApplication1::setLastEditedCommand(string c) {
	QString qt;
	ui.TextCtrlLastCommandEdited->setText(qt.fromStdString(c));
}

QTextEdit* QtGuiApplication1::getTextOutCtrl() {
	return ui.TextCtrlOut;
}

void QtGuiApplication1::addOutText(string t) {
	QString qt;
	ui.TextCtrlOut->append(qt.fromStdString(t));
}

void QtGuiApplication1::doCommendFun() {
	controler->doCommendButtonPressed();
}
