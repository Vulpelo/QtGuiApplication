#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include "ui_QtGuiApplication1.h"

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

private:
	Ui::QtGuiApplication1Class ui;

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
	void play();

};
