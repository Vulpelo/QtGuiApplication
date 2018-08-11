#pragma once

#ifndef QTGUIAPPLICATION1_H
#define QTGUIAPPLICATION1_H

#include "ui_MainWindow.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include <fstream>

#include "ThreadData.h"
#include "IView.h"
#include "ICon.h"

using namespace std;

class SimpleCommandWriter : public QMainWindow, public IView
{
	Q_OBJECT
	ICon *controler;
	Ui::QtGuiApplication1Class ui;

public:
	SimpleCommandWriter(QWidget *parent = Q_NULLPTR);

	void Execute(ICon *ncontroler);

#pragma region IView functions
	// Returns string that was written in command text edit box
	string getCommendText();
	void setLastEditedCommand(string c);
	// Returns pointer to text edit box wich prints all notifications out
	QTextEdit* getTextOutCtrl();
	void addOutText(string t);
#pragma endregion

public slots:
	void doCommendFun();
};

#endif // !QTGUIAPPLICATION1_H
