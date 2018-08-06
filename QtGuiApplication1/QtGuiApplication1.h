#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QThread>

#include <fstream>

#include "aiFunctions.h"

using namespace std;


class MyThread : public QThread
{
	//wxFrame* m_parent;
	Q_OBJECT

	void run() override {
		QString result;

		sleep(sleepTime);

		string commendText;//cout<<"*\n";
		if (commendNumber == "P000")
		{//cout<<"*P000\n";
			commendText.insert(0, commendMain + " ");
			int nrr = 1;
			while (PobSlowZWiersza(commendText, nrr) != "|$|$|" && PobSlowZWiersza(commendText, nrr) != " ") nrr++;
			if (PobSlowZWiersza(commendText, nrr) == " ")
			{
				//cout<< "B³¹d polecenia komendy P000; Nieznaleziono miejsca pozycji dla zmiennej "<<commendVariables<<" !!!"<<endl;
			}
			else
			{
				ZamienianieSlow(commendText, commendVariables, nrr);
				//commendText.insert(commendText.size(),commendVariables);
				char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
				for (int i = 0; i<commendText.size(); i++) T[i] = commendText[i];
				system(T);
			}
		}
		else if (commendNumber == "P001")
		{//cout<<"*P001\n";
			char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
			for (int i = 0; i<commendVariables.size(); i++) T[i] = commendVariables[i];
			system(T);
		}
		else if (commendNumber == "P002")
		{//cout<<"*P002\n";
			char T[100]; for (int i = 0; i<100; i++) T[i] = '\0';
			for (int i = 0; i<commendMain.size(); i++) T[i] = commendMain[i]; cout << commendMain << endl;
			system(T);
		}

		/*
		Powiadomienia, Potwierdzenia wykonania
		*/
		if (nrPowiadomienia == 1)
		{
			string textout = "", textline;
			ifstream wejout("out.txt");
			while (getline(wejout, textline))
			{
				textout += textline;
			}
			QString qtextout; qtextout.fromStdString(textout);

			wskTextCtrlOut->setText(qtextout);
			wejout.close();
			remove("out.txt");
		}
		else if (nrPowiadomienia == 2)
		{
			char T[] = "pwd > out.txt";
			system(T);
			string textout = "Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu:\n", textline;
			ifstream wejout("out.txt");
			getline(wejout, textline);

			textout += textline + "/ScreenShot.png\n";

			QString qtextout; qtextout.fromStdString(textout);
			wskTextCtrlOut->setText(qtextout);
			wejout.close();
			remove("out.txt");
			//wskTextCtrlOut->SetValue("Wykonano screenshot'a\nZdjecie zapisano w pliku o nazwie 'ScreenShot.png', w lokalizacji programu.");
			//wxMessageBox(wxT("HEJ!"));
		}
		//
		//wxSND(AI_inWX_0_0_1Frame);
		//long x=wxSND->ShowModal();

		//return;

		emit resultReady(result);
	}

public:
	MyThread()
	{
		//m_parent = parent;
	}

	string commendNumber;
	string commendVariables;
	string commendMain;
	//ScreenshotNotificationDialog* wxSND;
	short nrPowiadomienia;
	long sleepTime;
	QTextEdit* wskTextCtrlOut;

signals:
	void resultReady(const QString &s);
};


class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication1Class ui;

public:
	void Execute() {
		QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(doCommendFun()));
	}
public slots:
	void doCommendFun() {

		short numberOfErrors = 0;

		fstream slowazmienne("slowa_zmienne.txt");
		fstream slowapolecen("slowa_polecen.txt");
		fstream nrpolecen("nr_polecen.txt");
		fstream deleteFindWords("wordsFindDelete.txt");
		string c, tekst;
		int nrSlowa = 1;
		bool jestCzas = 0;
		short polec = 0;/*!*/
		char myText[100];

		int myTextW = 0; for (int i = 0; i<100; i++) myText[i] = '\0';

		c = ui.textBoxCommand->text().toStdString();


		if (c.size() > 0)
		{
			//cout<<">";
			//getline(cin,c);
			ui.TextCtrlLastCommand->setText(stringToQString(c));
			DoKommendyPodstawowej(c, slowapolecen, nrpolecen, slowazmienne, deleteFindWords, numberOfErrors, ui.TextCtrlOut);
			
			ui.TextCtrlLastCommandEdited->setText(stringToQString(c));

			nrSlowa = 1;
			string wordCommendCombination = "";

			if (PobSlowZWiersza(c, 1) == "!000")//komenda"znajdz" "P002"
			{
				wordCommendCombination += "find ~";
				nrSlowa++;
				while (PobSlowZWiersza(c, nrSlowa) != " ")
				{
					if (PobSlowZWiersza(c, nrSlowa) == "obraz") //wyszukiwanie pliku graficznego
					{
						if (PobSlowZWiersza(c, nrSlowa + 1) == "$008")
						{
							wordCommendCombination += " -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.png'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.bmp'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jpg'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jpeg'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.gif'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jps'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.tiff'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.flif'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.xcf'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.psd'";
							wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.xpm' -a -iname '*'";
							nrSlowa += 2;
						}
						else
						{
							wordCommendCombination += " -iname '*.jpg' -o -iname '*.bmp' -o -iname '*.gif' -o -iname '*.jps' -o -iname '*.png' -o -iname '*.jpeg'";
							wordCommendCombination += " -o -iname '*.tiff' -o -iname '*.flif' -o -iname '*.xcf' -o -iname '*.xpm' -o -iname '*.psd'";
						}
					}
					else if (PobSlowZWiersza(c, nrSlowa) == "plik") //wyszukiwanie jakiegokolwiek typu pliku po nazwie
					{
						if (PobSlowZWiersza(c, nrSlowa + 1) == "$008")
						{
							wordCommendCombination += " -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*'";
							nrSlowa += 2;
						}
					}
					else if (PobSlowZWiersza(c, nrSlowa) == "$009") //wyszukiwanie po dacie modyfikacjii
					{
						if (PobSlowZWiersza(c, nrSlowa + 1) == "$010") //przed
						{
							wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
							nrSlowa += 2;
						}
						else if (PobSlowZWiersza(c, nrSlowa + 1) == "%000") //po
						{
							wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
							nrSlowa += 2;
						}
						else if (PobSlowZWiersza(c, nrSlowa + 1) == "$011") // miedzy
						{
							if (PobSlowZWiersza(c, nrSlowa + 2) < PobSlowZWiersza(c, nrSlowa + 3))
							{
								wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
								wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 3);
								nrSlowa += 3;
							}
							else
							{
								wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 3);
								wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
								nrSlowa += 3;
							}
						}
					}
					else if (PobSlowZWiersza(c, nrSlowa) == "$00A") //wyszukiwanie po rozmiarze
					{
						if (PobSlowZWiersza(c, nrSlowa + 1) == "$00B") //do x
						{
							wordCommendCombination += " -size -" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
							nrSlowa += 3;
						}
						else if (PobSlowZWiersza(c, nrSlowa + 1) == "$00C") //wiekszye od x
						{
							wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
							nrSlowa += 3;
						}
						else if (PobSlowZWiersza(c, nrSlowa + 1) == "$011")
						{
							if (PobSlowZWiersza(c, nrSlowa + 2) > PobSlowZWiersza(c, nrSlowa + 3))
								wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 4) + "-not -size +" + PobSlowZWiersza(c, nrSlowa + 3) + PobSlowZWiersza(c, nrSlowa + 3);
							else
								wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 3) + PobSlowZWiersza(c, nrSlowa + 4) + "-not -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
							nrSlowa += 4;
						}
					}

					nrSlowa++;
				}
				wordCommendCombination += "> out.txt ;";// gnome-open out.txt;";
														//tworzenie thread
				MyThread *t = new MyThread();

				t->commendMain = wordCommendCombination;
				t->commendNumber = "P002";
				t->commendVariables = "";
				t->sleepTime = 0;
				t->wskTextCtrlOut = ui.TextCtrlOut;
				t->nrPowiadomienia = 1;

				connect(t, &MyThread::resultReady, this, &QtGuiApplication1::handleResults);
				connect(t, &MyThread::finished, t, &QObject::deleteLater);
				t->start();

				/*
				nrSlowa=1;
				while(jestCzas==0 and PobSlowZWiersza(c,nrSlowa)!= " ")
				if(PobSlowZWiersza(c,nrSlowa)[0]=='%')jestCzas=1;
				else nrSlowa++;
				if(jestCzas)
				{
				t->sleepTime=TimeInMsec(StringToInteger(PobSlowZWiersza(c,nrSlowa+1)),PobSlowZWiersza(c,nrSlowa+2));
				jestCzas=false;
				}
				*/
				//wxMessageBox(wxT("Wykonywanie komendy"));
				ui.TextCtrlOut->setText("Wyszukiwanie...");
			}
			else //########################################################################################################################
			{

				 while (polec != 2 && PobSlowZWiersza(c, nrSlowa) != " ")
					if (PobSlowZWiersza(c, nrSlowa)[0] == '$') { wordCommendCombination += PobSlowZWiersza(c, nrSlowa) + " "; nrSlowa++; polec = 1; }/*!*/
					else if (polec != 1) { nrSlowa++; }
					else polec = 2;
					// TODO: End line for linux += ";/r";
					tekst = ""; wordCommendCombination += ";";
					for (int i = 0; i<IloscZmiennychPolecenia(wordCommendCombination, nrpolecen, numberOfErrors, ui.TextCtrlOut); i++)
					{
						tekst += PobSlowZWiersza(c, nrSlowa + i);
					}//cout<<c<<endl<<tekst<<endl;
					 //commend(NumerPolecenia(wordCommendCombination, nrpolecen), tekst, KomendaPoleceniaSystemu(wordCommendCombination, nrpolecen));

					 //Tworzenie w¹tku
					MyThread* t = new MyThread();

					t->commendMain = KomendaPoleceniaSystemu(wordCommendCombination, nrpolecen, numberOfErrors, ui.TextCtrlOut);
					t->commendNumber = NumerPolecenia(wordCommendCombination, nrpolecen, numberOfErrors, ui.TextCtrlOut);
					t->commendVariables = tekst;
					t->wskTextCtrlOut = ui.TextCtrlOut;

					if (wordCommendCombination == "$007 $006 ;\r")
						t->nrPowiadomienia = 2;


					nrSlowa = 1;
					while (jestCzas == 0 && PobSlowZWiersza(c, nrSlowa) != " ")
						if (PobSlowZWiersza(c, nrSlowa)[0] == '%')jestCzas = 1;
						else nrSlowa++;

					if (jestCzas)
					{
						t->sleepTime = TimeInMsec(StringToInteger(PobSlowZWiersza(c, nrSlowa + 1)), PobSlowZWiersza(c, nrSlowa + 2));
						jestCzas = false;
					}
					else t->sleepTime = 0;

					connect(t, &MyThread::resultReady, this, &QtGuiApplication1::handleResults);
					connect(t, &MyThread::finished, t, &QObject::deleteLater);
						
					t->start();

					//if (jestCzas) wxMessageBox(wxT("Wykonanie komendy po wskazanym czasie"));
					//else wxMessageBox(wxT("Wykonywanie komendy"));
			}



			//cout<<"AI: Co chcesz abym zrobil?(wcisnij ENTER aby zatwierdzic tekst)\n";
		};

		slowapolecen.close();
		slowazmienne.close();
		nrpolecen.close();
		deleteFindWords.close();
	}

	void handleResults(){}
};
