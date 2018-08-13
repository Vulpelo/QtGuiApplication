#pragma once
#include <QtWidgets>

#include "ui_addsynonim.h"
#include "IAddSynonimContr.h"

class AddSynonim : public QWidget {
	Q_OBJECT

		IAddSynonimContr *ctr;

public:
	AddSynonim(QWidget * parent = Q_NULLPTR);
	void Execute(IAddSynonimContr *nctr);
	~AddSynonim();

private:
	Ui::AddSynonim ui;

public slots:
	void addButtonClicked();

};
