#include "addsynonim.h"

AddSynonim::AddSynonim(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

void AddSynonim::Execute(IAddSynonimContr * nctr)
{
	ctr = nctr;
	//QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));

}

void AddSynonim::addButtonClicked() {
	ctr->addButtonPressed(ui.mainWordLineEdit->text().toStdString(), ui.newWordLineEdit->text().toStdString());
}

AddSynonim::~AddSynonim() {
	delete ctr;
}
