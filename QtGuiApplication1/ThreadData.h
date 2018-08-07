#pragma once

#ifndef ThreadData_H
#define ThreadData_H

#include <string>
#include <QtWidgets/QTextEdit>
#include <QThread>
#include <fstream>
#include <iostream>

using namespace std;

struct ThreadData
{
	string commendNumber;
	string commendVariables;
	string commendMain;
	//ScreenshotNotificationDialog* wxSND;
	short nrPowiadomienia;
	long sleepTime;
	QTextEdit* wskTextCtrlOut;
};

class MyThread : public QThread
{
	Q_OBJECT

public:
		ThreadData data;

private:
	//Zwraca wybrane slowo z zdania string
	string PobSlowZWiersza(string c, int nr) 
	{
		int pozp = 0, pozk = 0, anr = 0;
		string s;
		while (pozk<c.size())
		{
			while (c[pozk] != ' ' && c[pozk] != '\0' && c[pozk] != '\n' && c[pozk] != '\r') pozk++;
			anr++;
			if (anr == nr) return s.insert(0, c, pozp, pozk - pozp);
			else { pozk++; pozp = pozk; };
		}
		//cout << "!!!Nie istnieje taki numer slowa!!!\n";
		return " ";
	}

	//podmienia slowo string z slowem w zdaniu string
	string ZamienianieSlow(string & c, string nowe, int NumerSlowa) 
	{
		int pozp = 0, pozk = 0, anr = 0;
		while (pozk<c.size())
		{
			while (c[pozk] != ' ' && c[pozk] != '\0') pozk++;
			anr++;
			if (anr == NumerSlowa)
			{
				if (nowe == "/delete/") return c.erase(pozp, pozk - pozp + 1);
				c.erase(pozp, pozk - pozp);
				return c.insert(pozp, nowe);
			}
			else { pozp = pozk + 1; pozk++; };
		}
	}

	void run() override 
	{
		QString result;

		sleep(data.sleepTime);

		string commendText;
		if (data.commendNumber == "P000")
		{
			commendText.insert(0, data.commendMain + " ");
			int nrr = 1;
			while (PobSlowZWiersza(commendText, nrr) != "|$|$|" && PobSlowZWiersza(commendText, nrr) != " ") 
				nrr++;
			if (PobSlowZWiersza(commendText, nrr) == " ")
			{
				//cout<< "Błąd polecenia komendy P000; Nieznaleziono miejsca pozycji dla zmiennej "<<commendVariables<<" !!!"<<endl;
			}
			else
			{
				ZamienianieSlow(commendText, data.commendVariables, nrr);
				//commendText.insert(commendText.size(),commendVariables);
				char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
				for (int i = 0; i<commendText.size(); i++) T[i] = commendText[i];
				system(T);
			}
		}
		else if (data.commendNumber == "P001")
		{
			char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
			for (int i = 0; i<data.commendVariables.size(); i++)
				T[i] = data.commendVariables[i];
			system(T);
		}
		else if (data.commendNumber == "P002")
		{
			char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
			for (int i = 0; i<data.commendMain.size(); i++) 
				T[i] = data.commendMain[i]; 
			//cout << data.commendMain << endl;
			system(T);
		}

		/*
		Powiadomienia, Potwierdzenia wykonania
		*/
		if (data.nrPowiadomienia == 1)
		{
			string textout = "", textline;
			ifstream wejout("out.txt");
			while (getline(wejout, textline))
			{
				textout += textline;
			}
			QString qtextout; qtextout.fromStdString(textout);

			data.wskTextCtrlOut->setText(qtextout);
			wejout.close();
			remove("out.txt");
		}
		else if (data.nrPowiadomienia == 2)
		{
			char T[] = "pwd > out.txt";
			system(T);
			string textout = "Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu:\n", textline;
			ifstream wejout("out.txt");
			getline(wejout, textline);

			textout += textline + "/ScreenShot.png\n";

			QString qtextout; qtextout.fromStdString(textout);
			data.wskTextCtrlOut->setText(qtextout);
			wejout.close();
			remove("out.txt");
			//wskTextCtrlOut->SetValue("Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu.");
		}

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

