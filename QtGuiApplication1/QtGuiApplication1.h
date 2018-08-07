#pragma once

#ifndef QTGUIAPPLICATION1_H
#define QTGUIAPPLICATION1_H

#include "ui_QtGuiApplication1.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include <fstream>

#include "ThreadData.h"
#include "ICom.h"

using namespace std;

class QtGuiApplication1 : public QMainWindow, public IView
{
	Q_OBJECT
	ICon *controler;
	Ui::QtGuiApplication1Class ui;

private:
	Ui::QtGuiApplication1Class ui;

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
	void play();

	void Execute(ICon *ncontroler);

	string getCommendText();
	void setLastEditedCommand(string c);
	QTextEdit* getTextOutCtrl();
	void addOutText(string t);

public slots:
	void doCommendFun();

};

#endif // !QTGUIAPPLICATION1_H
