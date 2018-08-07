#pragma once

#ifndef QTGUIAPPLICATION1_H
#define QTGUIAPPLICATION1_H

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include <fstream>

#include "ThreadData.h"
#include "ICom.h"

using namespace std;

typedef void(*doCommendF)();

class QtGuiApplication1 : public QMainWindow, public IView
{
	Q_OBJECT

	ICon *controler;

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);

public:
	void Execute(ICon *ncontroler);

private:
	Ui::QtGuiApplication1Class ui;

public:
	string getCommendText() {
		// setting last written command
		ui.TextCtrlLastCommand->setText(ui.textBoxCommand->text());
		// returning written command
		return ui.textBoxCommand->text().toStdString();
	}
	void setLastEditedCommand(string c) {
		QString qt;
		ui.TextCtrlLastCommandEdited->setText(qt.fromStdString(c));
	}

	QTextEdit* getTextOutCtrl() {
		return ui.TextCtrlOut;
	}

	void addOutText(string t) {
		QString qt;
		ui.TextCtrlOut->append(qt.fromStdString(t));
	}
public slots:
	void doCommendFun() {
		controler->doCommendButtonPressed();
	}
};

#endif // !QTGUIAPPLICATION1_H
