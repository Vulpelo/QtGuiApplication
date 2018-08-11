#pragma once

#ifndef ThreadData_H
#define ThreadData_H

#include <QtWidgets/QTextEdit>
#include <QThread>

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

#include "ErrorHandle.h"
#include "IView.h"
#include "StringMod.h"

using namespace std;

struct ThreadData
{
	string commendNumber;
	string commendVariables;
	string commendMain;
	short nrPowiadomienia;
	long sleepTime;
	IView* view;
};

class MyThread : public QThread
{
	Q_OBJECT

public:
		ThreadData data;

private:
	string notification(int nr)
	{
		string textout = "";
		if (nr == 1)
		{
			string textline;
			ifstream wejout("out.txt");
			while (getline(wejout, textline))
			{
				textout += textline;
			}
			wejout.close();
			remove("out.txt");
			return textout;
		}
		else if (nr == 2)
		{
			char T[] = "pwd > out.txt";
			system(T);
			string textline;
			textout = "Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu:\n";
			ifstream wejout("out.txt");
			getline(wejout, textline);

			textout += textline + "/ScreenShot.png\n";

			data.view->addOutText(textout);
			wejout.close();
			remove("out.txt");
			//wskTextCtrlOut->SetValue("Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu.");
			return textout;
		}
		return "";
	}

	void run() override 
	{
		QString result;

		sleep(data.sleepTime);

		string commendText;
		char T[100];
		for (int i = 0; i < 100; i++)
			T[i] = '\0';

		if (data.commendNumber == "P000")
		{
			commendText.insert(0, data.commendMain + " ");
			int nrr = 1;
			while (StringMod::PobSlowZWiersza(commendText, nrr) != "|$|$|" && StringMod::PobSlowZWiersza(commendText, nrr) != " ")
				nrr++;
			if (StringMod::PobSlowZWiersza(commendText, nrr) == " ")
			{
				data.view->addOutText(ErrorHandle::getString(ErrorType::E_COMMAND_CREATE, "P000"));
				//cout<< "Błąd polecenia komendy P000; Nieznaleziono miejsca pozycji dla zmiennej "<<commendVariables<<" !!!"<<endl;
			}
			else
			{
				StringMod::ZamienianieSlow(commendText, data.commendVariables, nrr);
				for (int i = 0; i<commendText.size(); i++) 
					T[i] = commendText[i];
				system(T);
			}
		}
		else if (data.commendNumber == "P001")
		{
			for (int i = 0; i < data.commendVariables.size(); i++)
				T[i] = data.commendVariables[i];
			system(T);
		}
		else if (data.commendNumber == "P002")
		{
			for (int i = 0; i < data.commendMain.size(); i++) 
				T[i] = data.commendMain[i]; 
			system(T);
		}

		notification(data.nrPowiadomienia);

		emit resultReady(result);
	}

public:
	MyThread() {}

signals:
	void resultReady(const QString &s);
};

class ThreadHandle : public QThread{
	Q_OBJECT

public:
	void setStart(MyThread* t) {
		connect(t, &MyThread::resultReady, this, &ThreadHandle::handleResults);
		connect(t, &MyThread::finished, t, &QObject::deleteLater);

		t->start();
	}

public slots:
	void handleResults(){}
};

#endif // !ThreadData_H
