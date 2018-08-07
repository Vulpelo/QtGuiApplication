#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <ctime>

#include <QtWidgets\QTextEdit>

using namespace std;


QString stringToQString(string s);

void wait(int howLongInMs);

long long StringToInteger(string c);

string PobSlowZWiersza(string c, int nr); //Zwraca wybrane sÂ³owo z zdania string

string ZamienianieSlow(string & c, string nowe, int NumerSlowa); //podmienia slowo string z slowem w zdaniu string

int IloscZmiennychPolecenia(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut);

string NumerPolecenia(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut); //wyszukuje i zwraca kod polecenia dla danego numeru sÂ³owa

string KomendaPoleceniaSystemu(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut);

string KodSlowaKluczowego(string szukaneSlowo, fstream & slowaPolecen, short &error, QTextEdit* wskTextCtrlOut);

string DoKommendyPodstawowej(string & c, fstream & slowa, fstream & polecenia, fstream & slowaZmienne, fstream & deleteFindWords, short &error, QTextEdit* wskTextCtrlOut); //Upraszcza wiersz polecenia do formy odpowiedniej, dla uÂ³atwienia odczytania komend


long long TimeInMsec(int czas, string typCzasu);

void commend(string commendNumber, string commendVariables, string commendMain);
