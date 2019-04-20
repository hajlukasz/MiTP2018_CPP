#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>   //zapisywanie i odczyt pliku
#include <string>
#include <vector>
#include <conio.h>   //funkcja getch

using namespace std;

void menu();    //funkcja glownego menu
void add_();
string aa();    //funkcje pytajace o parametry spotkania przy jego dodawaniu
string bb();
string cc();
string dd();
string ee();
string ff();

class Meeting   //pojedyncze spotkanie
{
public:
    string name;
    string place;
    string type;
    string date;
    string timee;
    string priorityy;

    Meeting(string n, string plc, string typ, string d, string tim, string pri):name(n), place(plc), type(typ), date(d), timee(tim), priorityy(pri) {}  //konstruktor

    string toString()   //funkcja potrzebna przy zapisywaniu danych do pliku
    {
        return (name+"\n"+place+"\n"+type+"\n"+date+"\n"+timee+"\n"+priorityy+"\n" );
    }

};

class meetings
{
  public:
    vector<Meeting> meetingss;   //wektor spotkan

    void add(Meeting o)     //funkcja dodajaca kolejne spotkania do wektora
    {
      meetingss.push_back(o);
    }

    void save()     //funkcja zapisujaca dane do pliku
    {
      ofstream plik("plik.txt");
      for(vector<Meeting>::iterator i = meetingss.begin();i<meetingss.end();i++)
      plik<<i->toString();
      plik.close();
    }

    void load()     //funkcja pobierajaca dane z pliku
    {
      ifstream plik("plik.txt");
        string n,plc,typ,d,tim,pri;
        string linia;
        int nr_linii = 1;
        while(getline(plik, linia))
        {
            switch(nr_linii)
            {
                case 1: n = linia; break;
                case 2: plc = linia; break;
                case 3: typ = linia; break;
                case 4: d = linia; break;
                case 5: tim = linia; break;
                case 6: pri = linia; break;
            };

            if(nr_linii==6)
                {
                    Meeting tmp(n,plc,typ,d,tim,pri);
                    meetingss.push_back(tmp);
                    nr_linii=0;
                }
            nr_linii++;
        }

    }

    void show()     //funkcja pokazujaca wszystkie zapisane spotkania
    {
        for(int i=0;i<meetingss.size();i++)
        {
        cout<< i + 1 <<".";
        cout<< meetingss[i].name<<" | "<<meetingss[i].place<<" | "<<meetingss[i].type<<" | "<<meetingss[i].date<<" | "<<meetingss[i].timee<<" | "<<meetingss[i].priorityy <<endl;
        }
    }

    void dlt()      //funkcja przeprowadzajaca przez proces usuwania spotkania
    {
        system( "cls" );

        meetings test;
        int d;
        char znak;

        test.load();
        test.show();

        cout << endl << "Nacisnij [S] aby rozpoczac usuwanie lub [Q] aby wrocic do menu: "
        << endl << "Inny przycisk konczy prace programu.";
        znak = getch();
        if(znak == 's')
        {
        cout << endl <<"Podaj numer spotkania, ktore chcesz usunac: ";
        cin >> d;
        d--;
        cout << "Czy na pewno chcesz usunac spotkanie? " << endl << "Tak [Y]: ";

        znak = getch();

        cout << endl;

        if( znak == 'y' ) {test.meetingss.erase (test.meetingss.begin() + d);}
        else {test.dlt(); }

        test.save();

        system( "cls" );

        cout << "Spotkanie zostalo pomyslnie usuniete, aby rozpoczac ponowne usuwanie nacisnij [S]; aby wrocic do menu nacisnij [Q]: ";
        znak = getch();
        if(znak == 's') { test.dlt();}
        else if( znak == 'q') {menu();}
        }
        else if( znak == 'q') {menu();}
    }

    void edit()
    {
        cin.sync();
        system( "cls" );

        meetings test;
        int c,d;
        string zmiana;

        test.load();
        test.show();

        cout << "Podaj numer spotkania, ktore chcesz edytowac nastepnie nacisnij [Enter]: ";
        cin >> d;
        d--;

        if( d >= 0 && d <= test.meetingss.size())
        {
            char znak;
            cout << "Podaj, ktory element spotkania chcesz edytowac: " << endl
            << "[1] - Nazwa;  [2] - Miejsce;  [3] - Typ;  [4] - Data;  [5] - Czas;  [6] - Waznosc" << endl;
            znak = getch();
            if(znak == '1')
            {
                cin.sync();
                zmiana = aa();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].name = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }
                else
				menu();
            }
            else if(znak == '2')
            {
                cin.sync();
                zmiana = bb();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].place = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }

                else
                menu();

            }
            else if(znak == '3')
            {
                cin.sync();
                zmiana = cc();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].type = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }

                else
                menu();

            }
            else if(znak == '4')
            {
				cin.sync();
                zmiana = dd();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].date = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }

                else
                menu();

            }
            else if(znak == '5')
            {
                cin.sync();
                zmiana = ee();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].timee = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }

                else
                menu();

            }
            else if(znak == '6')
            {
                cin.sync();
                zmiana = ff();

                cout << endl << "Czy na pewno chcesz zapisac zmiany? Tak [Y]: "
                << endl << "Wcisniecie innego przycisku niz [Y] - powrot do menu.";
                znak = getch();
                if ( znak == 'y')
                {
                test.meetingss[d].priorityy = zmiana;
                test.save();

                system( "cls" );

                cout << "Edycja  pomyslnie zakonczona.";
                Sleep(2500);
                menu();

                }

                else
                menu();

            }
                else
                {
                    system( "cls" );
                    cout << "Brak takiego parametru spotkania, sprobuj ponownie.";
                    Sleep(2500);
                    menu();
                }
        }
        else
        {
            system( "cls" );
            cout << "Brak takiego numeru spotkania, sprobuj ponownie.";
            Sleep(2500);
            menu();
        }
    }
};



int main()
{
    menu(); //wywolanie glownego menu

}

//Ponizej zaimplementowane funkcje uzyte w programie, ktore zostaly zadeklarowane na poczatku

void menu()
{
   {

   system( "cls" );    //funkcja czyszczaca ekran
     cout<< endl << endl
	<< "	 ########  " << endl
    << "	###    ### " << endl
    << "	###    ### " << endl
    << "	###    ### " << endl
    << "	###    ### " << endl
    << "	###    ### " << endl
    << "	 ########  " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;


        Sleep(75);
        system ( "cls" );

         cout<< endl << endl
	<< "	 ########  #########  " << endl
    << "	###    ### ###    ### " << endl
    << "	###    ### ###    ### " << endl
    << "	###    ### #########  " << endl
    << "	###    ### ###    ### " << endl
    << "	###    ### ###    ### " << endl
    << "	 ########  ###    ### " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

        Sleep(75);
        system ( "cls");

         cout<< endl << endl
	<< "	 ########  #########   ########  " << endl
    << "	###    ### ###    ### ###    ### " << endl
    << "	###    ### ###    ### ###        " << endl
    << "	###    ### #########  ###        " << endl
    << "	###    ### ###    ### ###   #### " << endl
    << "	###    ### ###    ### ###    ### " << endl
    << "	 ########  ###    ###  ########  " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

    Sleep(75);
        system ( "cls");

     cout<< endl << endl
	<< "	 ########  #########   ########      ###     " << endl
    << "	###    ### ###    ### ###    ###   ### ###   " << endl
    << "	###    ### ###    ### ###         ###   ###  " << endl
    << "	###    ### #########  ###        ########### " << endl
    << "	###    ### ###    ### ###   #### ###     ### " << endl
    << "	###    ### ###    ### ###    ### ###     ### " << endl
    << "	 ########  ###    ###  ########  ###     ### " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;


    Sleep(75);
        system ( "cls");

         cout<< endl << endl
	<< "	 ########  #########   ########      ###     ####    ### " << endl
    << "	###    ### ###    ### ###    ###   ### ###   #####   ### " << endl
    << "	###    ### ###    ### ###         ###   ###  ######  ### " << endl
    << "	###    ### #########  ###        ########### ### ### ### " << endl
    << "	###    ### ###    ### ###   #### ###     ### ###  ###### " << endl
    << "	###    ### ###    ### ###    ### ###     ### ###   ##### " << endl
    << "	 ########  ###    ###  ########  ###     ### ###    #### " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

    Sleep(75);
        system ( "cls");

     cout<< endl << endl
	<< "	 ########  #########   ########      ###     ####    ### ########### " << endl
    << "	###    ### ###    ### ###    ###   ### ###   #####   ###     ###     " << endl
    << "	###    ### ###    ### ###         ###   ###  ######  ###     ###     " << endl
    << "	###    ### #########  ###        ########### ### ### ###     ###     " << endl
    << "	###    ### ###    ### ###   #### ###     ### ###  ######     ###     " << endl
    << "	###    ### ###    ### ###    ### ###     ### ###   #####     ###     " << endl
    << "	 ########  ###    ###  ########  ###     ### ###    #### ########### " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

    Sleep(75);
        system ( "cls");

     cout<< endl << endl
	<< "	 ########  #########   ########      ###     ####    ### ########### ######### " << endl
    << "	###    ### ###    ### ###    ###   ### ###   #####   ###     ###          ###  " << endl
    << "	###    ### ###    ### ###         ###   ###  ######  ###     ###         ###   " << endl
    << "	###    ### #########  ###        ########### ### ### ###     ###        ###    " << endl
    << "	###    ### ###    ### ###   #### ###     ### ###  ######     ###       ###     " << endl
    << "	###    ### ###    ### ###    ### ###     ### ###   #####     ###      ###      " << endl
    << "	 ########  ###    ###  ########  ###     ### ###    #### ########### ######### " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

    Sleep(75);
        system ( "cls");

     cout<< endl << endl
	<< "	 ########  #########   ########      ###     ####    ### ########### ######### ########## " << endl
    << "	###    ### ###    ### ###    ###   ### ###   #####   ###     ###          ###  ###        " << endl
    << "	###    ### ###    ### ###         ###   ###  ######  ###     ###         ###   ###        " << endl
    << "	###    ### #########  ###        ########### ### ### ###     ###        ###    ########   " << endl
    << "	###    ### ###    ### ###   #### ###     ### ###  ######     ###       ###     ###        " << endl
    << "	###    ### ###    ### ###    ### ###     ### ###   #####     ###      ###      ###        " << endl
    << "	 ########  ###    ###  ########  ###     ### ###    #### ########### ######### ########## " << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

    Sleep(75);
        system ( "cls");

     cout<< endl << endl
	<< "	 ########  #########   ########      ###     ####    ### ########### ######### ########## ######### " << endl
    << "	###    ### ###    ### ###    ###   ### ###   #####   ###     ###          ###  ###        ###    ###" << endl
    << "	###    ### ###    ### ###         ###   ###  ######  ###     ###         ###   ###        ###    ###" << endl
    << "	###    ### #########  ###        ########### ### ### ###     ###        ###    ########   ######### " << endl
    << "	###    ### ###    ### ###   #### ###     ### ###  ######     ###       ###     ###        ###    ###" << endl
    << "	###    ### ###    ### ###    ### ###     ### ###   #####     ###      ###      ###        ###    ###" << endl
    << "	 ########  ###    ###  ########  ###     ### ###    #### ########### ######### ########## ###    ###" << endl
    << endl << "		[1] - Wyswietl spotkania; [2] - Dodaj spotaknie; [3] - Usun spotkanie; [4] - Wyjscie" <<endl;

	cout<< endl << endl << endl << endl << endl << endl  << endl << endl << endl << endl << endl  << endl << endl << endl << endl
	<< "Created by: Lukasz Hajec, Piotr Mercik & Maciej Stankiewicz" << endl
	<< "Project MiTP, EiT 2018";
   }
    char _switch;
    _switch = getch();
    switch (_switch)
    {

       case '1':  //wyswietlanie wszystkich spotkan
    {
        system( "cls" );

        meetings test;
        test.load();
        test.show();

        cout<< endl << "Jesli chcesz wrocic do menu nacisnij [Q] " <<endl;
        cout<<"Jesli chcesz edytowac spotkanie nacisnij [E]" <<endl;
        cout<<"Nacisniecie innego przycisku spowoduje koniec pracy programu.";

        char znak;
        znak = getch();
        if( znak == 'q' ){menu();}
        else if (znak == 'e') {test.edit();}

        break;
    }

    case '2': // dodawanie spotkania
    {
        add_();
    }

    case '3':  //usuwanie spotkan
    {
    system( "cls" );

    meetings test;
    test.load();
    test.show();

    {test.dlt(); }

    break;
    }

    case '4':   // wyjscie z programu
    {
        exit (0);

    }

    default:    //opcja rozwiazujaca problem bledu uzytkownika
    {
        system( "cls" );
        cout<<"Przykro nam, ale poki co nie ma takiej funkcji, caly czas pracujemy nad udoskonalaniem naszego kodu, stay tuned :) ";
        Sleep(2500);
        _switch=NULL;
        menu();
        break;
    }
    }

}

string aa()
{
    string a;
    cout << "Podaj nazwe wlasna spotkania: "<<endl;
    getline (cin,a);
    return(a);
}

string bb()
{
    string a;
     cout << "Podaj miejsce spotkania: "<<endl;
     getline (cin,a);
     return(a);
}

string cc()
{
    string a;
     cout << "Wybierz rodzaj spotkania: " << endl;
     cout << "- Zawodowe " << endl << "- Prywatne " << endl << "- Impreza " << endl << "- Inne " << endl;
     getline (cin,a);
     return(a);
}

string dd()
{
    string a;
     cout << "Podaj date w nastepujacym formacie - DD/MM/YYYY - : "<<endl;
     getline (cin,a);
     return(a);
}

string ee()
{
    string a;
     cout << "Podaj godzine w nastepujacym formacie - HH:MM - : "<<endl;
     getline (cin,a);
     return(a);
}

string ff()
{
    string a;
     cout << "Jak wazne jest to spotkanie: " << endl;
     cout << " Malo wazne   Wazne   Bardzo wazne" << endl;
     getline (cin,a);
     return(a);
}

void add_()
{
    system( "cls" );
    cin.sync(); 													// bez tego polaczenie zwyklego cin i getline (cin) zjada jedna linijke
    string a,b,c,d,e,f;                                             //wpisywanie samych funkcji do srodka obiektu klasy Meeting, miesza ich kolejnosc
    a = aa(); b = bb(); c = cc(); d = dd(); e = ee(); f = ff();
    Meeting abc(a,b,c,d,e,f);

    meetings test;
    test.load();
    test.add(abc);
    test.save();

    system( "cls" );

    cout<< "Spotkanie zostalo pomyslne dodane." << endl <<"Nacisnij [A], aby dodac kolejne spotkanie albo [Q], aby wrocic do menu: ";
    char znak;                      // powrot do menu, load normalnie by mi wyswietlil‚ sam ale tutaj jakos nie dziala w polaczeniu z tym getch()
    znak = getch();
    if( znak == 'q' ){menu();}
    else if( znak == 'a' ){add_();}
}

