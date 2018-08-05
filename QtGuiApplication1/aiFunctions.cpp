#include "aiFunctions.h"



using namespace std;

QString stringToQString(string s) {
	QString qs;
	qs = qs.fromStdString(s);
	return qs;
}

void wait(int howLongInMs)
{
    clock_t czas;
    czas=clock()+howLongInMs;
    while(czas>clock());
    return;
}

long long StringToInteger(string c)
{
    int liczba=0,tmp=0;
    for(int i=c.size()-1, j=1; i>=0; i--,j*=10)
    {
        tmp=c[i]-48;
        tmp=tmp*j;
        liczba+=tmp;
    }
    return liczba;
}
/*
string numeracja(char ACTUAL[],int i)
{
    if(i>=0)
    {
        ACTUAL[i]++;
        if(ACTUAL[i]==123)
            {
                ACTUAL[i]='0';
                numeracja(ACTUAL,i-1);
            }
        else if(ACTUAL[i]==91) ACTUAL[i]='a';
        else if(ACTUAL[i]==58) ACTUAL[i]='A';
    }
    return ACTUAL;
}
*/
string PobSlowZWiersza(string c, int nr) //Zwraca wybrane sÂ³owo z zdania string
{
    int pozp=0, pozk=0, anr=0;
    string s;
    while(pozk<c.size())
    {
        while(c[pozk] != ' ' && c[pozk] != '\0' && c[pozk] != '\n' && c[pozk] != '\r') pozk++;
        anr++;
        if(anr==nr) return s.insert(0,c,pozp,pozk-pozp);
        else {pozk++; pozp=pozk;};
    }
    cout<<"!!!Nie istnieje taki numer slowa!!!\n";
    return " ";
}

string ZamienianieSlow(string & c, string nowe, int NumerSlowa) //podmienia slowo string z slowem w zdaniu string
{
    int pozp=0, pozk=0, anr=0;
    while(pozk<c.size())
    {
        while(c[pozk] != ' ' && c[pozk] != '\0') pozk++;
        anr++;
        if(anr==NumerSlowa)
        {
            if(nowe=="/delete/") return c.erase(pozp,pozk-pozp+1);
            c.erase(pozp,pozk-pozp);
            return c.insert(pozp,nowe);
        }
        else {pozp=pozk+1; pozk++;};
    }
}

int IloscZmiennychPolecenia(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut)
{
    string wiersz,wierszWyj;//int nr=1;
    polecenia.clear(); polecenia.seekg(0);//??//!!//
    while(getline(polecenia,wiersz))
    {
        if(wiersz ==szukanyNumer)
        {
            getline(polecenia, wiersz);
            polecenia.clear(); polecenia.seekg(0);
            return StringToInteger(PobSlowZWiersza(wiersz,1));
        }//PobSlowZWiersza(wiersz,2);
        else getline(polecenia, wiersz);
    }
    error++;
    string wyjError="\n!#Blad w funkcji IloscZmiennychPolecenia &Brak danych w pliku 'nr_polecenia.txt' dla:'"+szukanyNumer+"'";
    wskTextCtrlOut->append(stringToQString(wyjError));
    cout<<"ERROR!:IloscZmiennychPolecenia#Brak danych w pliku nr_polecenia.txt dla:"<<szukanyNumer<<endl;
    return 0;
}



string NumerPolecenia(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut) //wyszukuje i zwraca kod polecenia dla danego numeru sÂ³owa
{
    string wiersz;
    while(getline(polecenia,wiersz))
        if(wiersz==szukanyNumer)
        {
            getline(polecenia,wiersz);
            polecenia.clear(); polecenia.seekg(0);
            return PobSlowZWiersza(wiersz,2);
        }
        else getline(polecenia,wiersz);
    error++;
    string wyjError="\n!#Blad w funkcji NumerPolecenia &Nieznaleniono numeru polecenia w pliku 'nr_polecenia.txt' dla:'"+szukanyNumer+"'";
    wskTextCtrlOut->append(stringToQString(wyjError));
    cout<<"ERROR!:NumerPolecenia#Nieznaleziono numeru polecenia z pliku \"nr_polecenia.txt\" dla: "<<szukanyNumer<<endl;
    return "";
}

string KomendaPoleceniaSystemu(string szukanyNumer, fstream & polecenia, short &error, QTextEdit* wskTextCtrlOut)
{
    string wiersz,wierszWyj="";
    while(getline(polecenia,wiersz))
        if(wiersz==szukanyNumer)
        {
            getline(polecenia,wiersz);
            int nr=3;
            while(PobSlowZWiersza(wiersz,nr) != ";" && PobSlowZWiersza(wiersz,nr) != " ")
            {
                wierszWyj+=PobSlowZWiersza(wiersz,nr);nr++;
                wierszWyj+=" ";
            }
        }
        else getline(polecenia,wiersz);
    polecenia.clear(); polecenia.seekg(0);
    return wierszWyj;
}

string KodSlowaKluczowego(string szukaneSlowo, fstream & slowaPolecen, short &error, QTextEdit* wskTextCtrlOut)
{
    slowaPolecen.clear();slowaPolecen.seekg(0);
    string p;
    int g=1;

        while(getline(slowaPolecen,p))
        {
            while(PobSlowZWiersza(p,g+1) != " ")  //SÂ³owo z wiersza z pliku
            {
            //Druga pÃªtla ktÃ³ra zamienia sÂ³owa zmiennych na sÂ³owa podstawowe(o ile istniejÂ±;sÂ± zapisane w pliku sÂ³owa_zmienne.txt)
                if(szukaneSlowo==PobSlowZWiersza(p,g+1))
                {
                    return PobSlowZWiersza(p,1);
                };
                g++;
            }
            g=1;
        }

    error++;
    string wyjError="\n!#Blad w funkcji KodSlowaKluczowego &Brak danych w pliku 'slowa_polecen.txt' dla:'"+szukaneSlowo+"'";
    wskTextCtrlOut->append(stringToQString(wyjError));
    cout<<"Nieznane slowo polecenia: "<<szukaneSlowo<<" . Nieodnalezione w \"slowa_polecen.txt\""<<endl;
    return " ";
}


void deleteWordsWithFile(string & c, fstream & deleteWords)
{
    string sZc, sZdeleteWords;
    int nrSlowa=1;
    bool found=false;
    sZc=PobSlowZWiersza(c, nrSlowa);
    while(sZc != " ")
    {
        deleteWords.clear(); deleteWords.seekg(0);
        deleteWords>>sZdeleteWords;
        while(deleteWords.good() && found==false)
        {
            if(sZc==sZdeleteWords)
            {
                ZamienianieSlow(c, "/delete/", nrSlowa);
                found=true;
            }
            deleteWords>>sZdeleteWords;
        }
        nrSlowa++;
        sZc=PobSlowZWiersza(c, nrSlowa);
        found=false;
    }
}





//Upraszcza wiersz polecenia do formy odpowiedniej, dla uÂ³atwienia odczytania komend
string DoKommendyPodstawowej(string & c, fstream & slowa, fstream & polecenia, fstream & slowaZmienne, fstream & deleteFindWords, short &error, QTextEdit* wskTextCtrlOut)
{
    for(int i=c.size()-1; i>=0; i--)    //Czyszczenie znakÃ³w poza literami(zamienianie ich z duÂ¿ych na maÂ³e) i cyframi
    {
        if(c[i]>='A' && c[i]<='Z') c[i]=c[i]+32;
        //nieusuwanie określonych znaków i takich w pewnych sytuacjach
        else if ((c[i]=='.' && c[i+1]>='a' && c[i+1]<='z') || c[i]=='*' || c[i]==39);
        else if((c[i]>=33 && c[i]<=47) || (c[i]>=58 && c[i]<=64) || (c[i]>=91 && c[i]<=96) || (c[i]>=123 && c[i]<=126))
                    c.erase(i,1);
    };

    string sZc,p="",tmpS,wierszSlowaZmienne;
    string lastSpecialWord;
    int wordNr=1, g=1, numberOfWordCombination=0;
    bool znalezione=false;

    sZc=PobSlowZWiersza(c, wordNr);    //sÂ³owo z wiersza c
    tmpS=KodSlowaKluczowego(sZc, slowa, error, wskTextCtrlOut);
    lastSpecialWord=tmpS;

    if(tmpS[0] =='!') deleteWordsWithFile(c, deleteFindWords);
    while(sZc != " ") //pÃªtla dla sÂ³owa z zdania wprowadzonego przez uÂ¿ytkownika
    {



        if(tmpS != " " && tmpS != ";" && lastSpecialWord[0] == tmpS[0])
        {
            //if(numberOfWordCombination>0)   //jeżeli specjalne słowo czasu i kommeny będą obok siebie
           // {
                lastSpecialWord=tmpS;
                g=1;polecenia.clear();polecenia.seekg(0);
                ZamienianieSlow(c,tmpS,wordNr);
                numberOfWordCombination++;
                p+=tmpS + " ";
            //}
           // else

            //}

        }
        else if(numberOfWordCombination>0)
        {p+=";\r"; //ustawia koncowy znak (koniec wierszu w linux'sie)
        if(IloscZmiennychPolecenia(p, polecenia, error, wskTextCtrlOut) >0)
            {

            for(int i=IloscZmiennychPolecenia(p, polecenia, error, wskTextCtrlOut); i>0; i--) //and znalezione==0 ?!?
            {//Sprawdzanie sÂ³Ã³w z innego pliku (SÂ³owa_zmienne.txt)

                sZc=PobSlowZWiersza(c, wordNr); slowaZmienne.clear(); slowaZmienne.seekg(0);
                while(znalezione==false && getline(slowaZmienne,wierszSlowaZmienne))
                {
                    while(PobSlowZWiersza(wierszSlowaZmienne,g)!=" " && znalezione==false)
                    {
                        if(sZc==PobSlowZWiersza(wierszSlowaZmienne,g))
                            {ZamienianieSlow(c,PobSlowZWiersza(wierszSlowaZmienne,1),wordNr); znalezione=true;}
                        g++;
                    }
                    g=1;
                }
                znalezione =false;
                wordNr++;
            }

            p="";
            wordNr--;
            numberOfWordCombination=0;
            }
            else
            {p="";
            wordNr--;
            numberOfWordCombination=0;
            }
        }
        else ZamienianieSlow(c, "/delete/", wordNr);

        wordNr++;g=1;znalezione=false;
        sZc=PobSlowZWiersza(c, wordNr);
        tmpS=KodSlowaKluczowego(sZc, slowa, error, wskTextCtrlOut);
        if(numberOfWordCombination==0)
            lastSpecialWord=tmpS;
    }
    slowa.clear();polecenia.clear();slowaZmienne.clear();
    slowa.seekg(0);polecenia.seekg(0);slowaZmienne.seekg(0);
    if(error<=0) wskTextCtrlOut->append("\n#Niewykryto problemow.");
    return c;
}



long long TimeInMsec(int czas, string typCzasu)
{
    //if(typCzasu=="sek")czas=czas*1000;
    if(typCzasu=="min")czas=czas*60;
    else if(typCzasu=="h")czas=czas*3600;
    return czas;
}

void commend(string commendNumber, string commendVariables, string commendMain)
{
    string commendText;cout<<"*\n";
    if(commendNumber=="P000")
    {cout<<"*P000\n";
        commendText.insert(0,commendMain+" ");
        int nrr=1;
        while(PobSlowZWiersza(commendText, nrr) != "|$|$| " && PobSlowZWiersza(commendText, nrr) != " ") nrr++;
        if(PobSlowZWiersza(commendText, nrr) != " ")
        {
            cout<< "Błąd polecenia komendy P000; Nieznaleziono miejsca pozycji dla zmiennej "<<commendVariables<<" !!!"<<endl;
            return;
        }
        ZamienianieSlow(commendText, commendVariables, nrr);
        //commendText.insert(commendText.size(),commendVariables);
        char T[100];for(int i=0; i<100; i++) T[i]='\0';
        for(int i=0; i<commendText.size(); i++) T[i]=commendText[i];
        system(T);
    }
    else if(commendNumber=="P001")
    {cout<<"*P001\n";
        char T[100];for(int i=0; i<100; i++) T[i]='\0';
        for(int i=0; i<commendVariables.size(); i++) T[i]=commendVariables[i];
        system(T);
    }
    else if(commendNumber=="P002")
    {cout<<"*P002\n";
        char T[100];for(int i=0; i<100; i++) T[i]='\0';
        for(int i=0; i<commendMain.size(); i++) T[i]=commendMain[i];cout<<commendMain<<endl;
        system(T);
    }
    return;
}






/*
void doCommand()
{
    if(myTextW>0)
    {
        c = myText;

        for(int i=0; i<100; i++) myText[i]='\0'; //Resetowanie wczytywanego tekstu i wska¼nika
        myTextW=0;

        DoKommendyPodstawowej(c, slowapolecen, nrpolecen,slowazmienne);


        //Sprawdzianie czy podany wiersz kommendy zawiera czas
        nrSlowa=1;cout<<c<<endl;
        while(jestCzas==0 and PobSlowZWiersza(c,nrSlowa)!= " ")
            if(PobSlowZWiersza(c,nrSlowa)[0]=='%')jestCzas=1;
            else nrSlowa++;




        //Wykonywanie polecenia
        if(jestCzas==1)
        {
            int g=0;
            while(Tasks[g].Active != 0 and g<NUMBER_OF_TASKS)g++;
            if(g>=NUMBER_OF_TASKS)
            {
                cout<<"!ERROR!!No free Time command slots\n";
                jestCzas=0;
            }
            else
            {cout<<"zawiera czas\n";
                Tasks[g].Active=1;
                Tasks[g].CreateTime=clock();
                Tasks[g].StartTaskTime=clock() + TimeInMsec(StringToInteger(PobSlowZWiersza(c,nrSlowa+1)),PobSlowZWiersza(c,nrSlowa+2));;
                Tasks[g].Variables=c;
                cout<<"zawiera czas\n"<<g<<" "<< Tasks[g].CreateTime<<" "<<Tasks[g].StartTaskTime<<endl<<nrSlowa<<endl;
                jestCzas=0;
            }
        }
        else //Jezeli niezawiera czasu
        {
            nrSlowa=1;
            string wordCommendCombination="";
            while(polec!=2 and PobSlowZWiersza(c,nrSlowa)!= " ")
                if(PobSlowZWiersza(c,nrSlowa)[0]=='$'){wordCommendCombination+=PobSlowZWiersza(c,nrSlowa)+" ";nrSlowa++;polec=1;}/*!*/
              /*  else if(polec!=1){nrSlowa++;}
                else polec=2;
            tekst="";
            for(int i=1; i<=IloscZmiennychPolecenia(wordCommendCombination,nrpolecen); i++)
            {
                tekst+=PobSlowZWiersza(c,nrSlowa+i);
            }cout<<c<<endl<<tekst<<endl;
            commend(NumerPolecenia(wordCommendCombination, nrpolecen), tekst, KomendaPoleceniaSystemu(wordCommendCombination, nrpolecen));
        }

        cout<<"AI: Co chcesz abym zrobil?(wcisnij ENTER aby zatwierdzic tekst)\n";
    };

}
*/
