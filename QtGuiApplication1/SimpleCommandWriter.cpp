#include "SimpleCommandWriter.h"

SimpleCommandWriter::SimpleCommandWriter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

SimpleCommandWriter::~SimpleCommandWriter()
{
}

void SimpleCommandWriter::Execute(ICon *ncontroler)
{
	controler = ncontroler;
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(doCommendFun()));
	QObject::connect(ui.actionSynonim, SIGNAL(triggered()), this, SLOT(actionSynonimPressed()));
	QObject::connect(ui.actionNowe_slowo, SIGNAL(triggered()), this, SLOT(actionNewWordPressed()));
}

string SimpleCommandWriter::getCommendText() {
	// setting last written command
	ui.TextCtrlLastCommand->setText(ui.textBoxCommand->text());
	// returning written command
	return ui.textBoxCommand->text().toStdString();
}

void SimpleCommandWriter::setLastEditedCommand(string c) {
	QString qt;
	ui.TextCtrlLastCommandEdited->setText(qt.fromStdString(c));
}

QTextEdit* SimpleCommandWriter::getTextOutCtrl() {
	return ui.TextCtrlOut;
}

void SimpleCommandWriter::addOutText(string t) {
	QString qt;
	ui.TextCtrlOut->append(qt.fromStdString(t));
}


void SimpleCommandWriter::doCommendFun() {
	controler->doCommendButtonPressed();
}

void SimpleCommandWriter::actionSynonimPressed() {
	AddSynonim *newWindow = new AddSynonim;

	newWindow->Execute(controler->getIAddSynonimCtr());
	newWindow->show();

	//controler->actionSynonimPressed();
}

void SimpleCommandWriter::actionNewWordPressed() {
	AddMainWord *nW = new AddMainWord;

	nW->Execute(controler->getIAddMainWordCtr());
	nW->show();
}
