#include "addsynonim.h"

AddSynonim::AddSynonim(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

void AddSynonim::Execute(IAddSynonimContr * nctr)
{
	ctr = nctr;
	QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
	QObject::connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

}

void AddSynonim::addButtonClicked() {
	ctr->addButtonPressed(ui.mainWordLineEdit->text().toStdString(), ui.newWordLineEdit->text().toStdString());
	close();
}

void AddSynonim::cancelButtonClicked() {
	close();
}

AddSynonim::~AddSynonim() {
	delete ctr;
}
