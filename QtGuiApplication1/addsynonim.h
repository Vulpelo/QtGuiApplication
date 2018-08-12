#pragma once
#include <QWidget>
#include "ui_addsynonim.h"

class AddSynonim : public QWidget {
	Q_OBJECT

public:
	AddSynonim(QWidget * parent = Q_NULLPTR);
	~AddSynonim();

private:
	Ui::AddSynonim ui;
};
