#pragma once
#include <QWidget>
#include "ui_AddMainWord.h"

#include "IAddMainWordCtr.h"

class AddMainWord : public QWidget {
	Q_OBJECT
		IAddMainWordCtr * ctr;

public:
	AddMainWord(QWidget * parent = Q_NULLPTR);
	void Execute(IAddMainWordCtr* nctr);
	~AddMainWord();

private:
	Ui::AddMainWord ui;

public slots:
	void addButtonClicked();
	void cancelButtonClicked();
};
