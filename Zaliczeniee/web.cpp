
/*7.Napisaæ  program   zarz¹dzaj¹cy has³ami dla   poszczególnych witryn   internetowych,   tj. umo¿liwiaj¹cy
zapisanie nowego has³a, któregou¿ytkownik u¿ywa w swojej przegl¹darce internetowej  (np.do  klienta  poczty,Facebooka,  Twittera itp.).
Informacje  w  bazie  powinny byæ zaszyfrowane za pomoc¹ klucza znanego tylko w³aœcicielowii udostêpnianetylko po jego podaniu.
Program ma umo¿liwiaæ dodawanie, modyfikacjê oraz usuwanie poszczególnych parwitryna-has³o. */
#include<map>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string cs = "34"; // haslo do odkodowania
string kodowanie(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = a[i] - 34;
    } return a;
}
string dekodowanie(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = a[i] + 34;
    } return a;
}


 int main()   
{
    map<string, string> lista;
    map<string, string>::iterator it;
    char wyb,s; string haslo_glowne, haslo, hasloG;
    ifstream check("pary.txt");
    fstream plik; //otwarcie plikow
    haslo_glowne = "WSBW1"; //haslo do modyfikacji
    if (check)
    {
        plik.open("pary.txt");
        while (!plik.eof()){
            string linia, klucz;
            getline(plik, linia);
            getline(plik, klucz);
            linia = dekodowanie(linia);
            klucz = dekodowanie(klucz);
            lista.insert(pair<string, string>(linia, klucz));

        } 
        plik.close();
    }
    while (true)
    {
       
        cout << " Czesc przyjacielu , witaj w internetach! \n Co robimy? \n q - wyjscie z programu \n p- wypisz pary witryna/haslo \n a - dodaj witryne i haslo \n d - usun witryne i haslo \n m - modyfikuj haslo \n czysc ekran - c \n    UWAGA! : Program jest case sensitive! \n";
       
        cin >> wyb;
        if (wyb == 'q'||wyb=='Q')
        {
            cout << " Zapisac zmiany? : \n t/T- tak n/N- nie\n";
            cin >> s;
            if (s == 'n' || s == 'N')
            {
                cout << " Papa! \n";
                return 0;
            }else   if (s == 't' ||s== 'T')
                {
                    plik.open("pary.txt",ios::out);
                    for (it = lista.begin(); it != lista.end(); it++)
                    {
                       plik<< kodowanie(it->first) << endl;
                        plik<< kodowanie(it->second)<< endl;
                    }
                    plik.close();
                    return 0;
            
                }

        } 
        if (wyb == 'p' || wyb == 'P')
        {
            //--------------------------------------------------------------------------------------------------------------------
            string key;
            cout << " Jesli chcesz ujrzec hasla, podaj kod! :"; cin >> key;
            if (key == "34")
            {
                for (it = lista.begin(); it != lista.end(); it++)
                {
                    cout << "Witryna: " << it->first << endl;
                    cout << "Haslo: " << it->second << endl;

                }
            }
            else {
                cout << " Zly kod! Nie zobaczysz hasel!\n";

                for (it = lista.begin(); it != lista.end(); it++)
                {
                    cout << "Witryna: " << kodowanie(it->first )<< endl;
                    cout << "Haslo: " << kodowanie(it->second) << endl;

                }
            }

           //----------------------------------------------------------------------------------------------------------------------- 
        }
        if (wyb == 'a'|| wyb=='A')
        {
            string witrynaa, hasloo;
            cin >> witrynaa >> hasloo;
            lista.insert(pair<string, string>(witrynaa, hasloo));
        }
        if (wyb == 'c'||wyb=='C') //czyszczenie ekranu
        {
            system("cls");
        }
        if(wyb=='m'||wyb=='M') // modyfikacja pary haslo/witryna, trzeba podac witryne
        {

            cout << "Wpisz haslo!: "; cin >> haslo;
            if (haslo == haslo_glowne)  // haslo_glowne jest haslem ukrytym w pliku 
            {
                string witryna;
                cin >> witryna;
                auto szukaj = lista.find(witryna);
                if (szukaj != lista.end())
                {
                    string haslo1;
                    cout << "Podaj nowe haslo : "; cin >> haslo1;
                    lista.find(witryna)->second = haslo1;
                }
            }
            else cout << "Zle haslo!";

        }
        if(wyb=='d'||wyb=='D') // usuniecie elementu
        {
            cout << "Wpisz haslo!: "; cin >> haslo;
            if (haslo ==haslo_glowne)
            {
                string witryna;
                cin >> witryna;
                auto szukaj = lista.find(witryna); // wyszukanie witryny i sprawdzenie czy faktycznie jest
                if (szukaj != lista.end())
                    lista.erase(szukaj);
            }
            else cout << "Zle haslo!";
        }
    }
}