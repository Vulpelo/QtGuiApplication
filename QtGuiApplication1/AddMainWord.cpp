#include "AddMainWord.h"

AddMainWord::AddMainWord(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

void AddMainWord::Execute(IAddMainWordCtr * nctr)
{
	ctr = nctr;
	QObject::connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
	QObject::connect(ui.CancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

}

void AddMainWord::addButtonClicked() {
	ctr->addButtonPressed(ui.NewMainWord_lineEdit->text().toStdString());
	close();
}

void AddMainWord::cancelButtonClicked() {
	close();
}

AddMainWord::~AddMainWord() {
	
}
