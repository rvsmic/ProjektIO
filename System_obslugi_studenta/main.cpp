#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Uczelnia.h"
#include "Uzytkownik.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Przedmiot.h"

using std::cout, std::cin;
using std::string;
using std::vector;


int main()
{
    Uczelnia* uczelnia = new Uczelnia("UMCS");

    Narzedzie* excel = new Narzedzie("Excel", "www.excel.com");
    Narzedzie* word = new Narzedzie("Word", "www.word.com");

    uczelnia->dodajNarzedzie(excel);
    uczelnia->dodajNarzedzie(word);

    bool EXIT_FLAG = false;
    bool error = false;

    Uzytkownik* user = NULL;

    char option = 0;

    string login, haslo;
    string wybor;

    bool czyStudent = false;

    cout << "Witaj na stronie uczelni " << uczelnia->getNazwa() << "!\n";
    system("pause");
    system("cls");

    while(!EXIT_FLAG){
        cout<<"\nS T R O N A   D O M O W A";
        if(user!=NULL) {
            if(user->czyStudent) {
                cout<<"   -   P A N E L   S T U D E N T A";
            } else {
                cout<<"   -   P A N E L   W Y K L A D O W C Y";
            }
        }
        cout<<"\n\n------------------------------\n\n";
        cout << "Wybierz opcje:\n";
        if(user == NULL){                       // WYLOGOWANY

            cout << "1 - Zaloguj sie\n2 - Zarejestruj sie\n9 - Wyjdz z programu\n\n";
            cout<<"------------------------------\n\n";
            cin >> option;
            system("cls");

            switch(option){
                case '1':{                  // LOGOWANIE
                    cout<<"\nL O G O W A N I E\n\n";
                    cout<<"------------------------------\n\n";
                    cout<<"1 - Logowanie dla studenta\n2 - Logowanie dla wykladowcy\n\n";
                    cout<<"------------------------------\n\n";
                    cin >> option;
                    system("cls");
                    switch(option){
                        case '1':{
                            cout<<"\nL O G O W A N I E   D L A   S T U D E N T A\n\n";
                            czyStudent = true;
                            break;
                        }
                        case '2':{
                            cout<<"\nL O G O W A N I E   D L A   W Y K L A D O W C Y\n\n";
                            czyStudent = false;
                            break;
                        }
                        default: {
                            cout<<"Brak opcji o kodzie "<<option<<"\n";
                            error = true;
                            system("pause");
                            break;
                        }
                    }
                    cout<<"------------------------------\n\n";
                    if(error) {
                        error = false;
                        break;
                    }
                    cout<<"Podaj login: ";
                    cin >> login;
                    cout<<"Podaj haslo: ";
                    cin >> haslo;
                    cout<<"\n------------------------------\n\n";

                    user = uczelnia->logowanie(login, haslo, czyStudent);
                    if(user != NULL){
                        break;
                    } else {
                        cout << "Czy chcesz sie zarejestrowac?\n1 - Tak\n2 - Nie\n\n";
                        cout<<"------------------------------\n\n";
                        cin >> option;
                        cout<<"\n";
                        if(option == '1'){
                            cout<<"Przejscie do rejestracji...\n";
                            system("pause");
                            system("cls");
                        } else if (option == '2'){
                            system("cls");
                            cout<<"Powrot do ekranu poczatkowego...\n\n";
                            system("pause");
                            break;
                        } else {
                            system("cls");
                            cout<<"Bledna opcja, powrot do ekranu poczatkowego...\n\n";
                            system("pause");
                            break;
                        }
                    }
                }
                case '2':{ // REJESTRACJA
                    cout<<"\nR E J E S T R A C J A\n\n";
                    cout<<"------------------------------\n\n";
                    cout<<"1 - Rejestracja dla studenta\n2 - Rejestracja dla wykladowcy\n\n";
                    cout<<"------------------------------\n\n";
                    cin >> option;
                    system("cls");
                    switch(option){
                        case '1':{
                            cout<<"\nR E J E S T R A C J A   D L A   S T U D E N T A\n\n";
                            czyStudent = true;
                            break;
                        }
                        case '2':{
                            cout<<"\nR E J E S T R A C J A   D L A   W Y K L A D O W C Y\n\n";
                            czyStudent = false;
                            break;
                        }
                        default: {
                            cout<<"Brak opcji o kodzie "<<option<<"\n\n";
                            error = true;
                            system("pause");
                            break;
                        }
                    }
                    cout<<"------------------------------\n\n";
                    if(error) {
                        error = false;
                        break;
                    }

                    cout<<"Podaj login: ";
                    cin >> login;
                    cout<<"Podaj haslo: ";
                    cin >> haslo;
                    user = uczelnia->rejestracja(login, haslo, czyStudent);
                    if(user == NULL){
                        system("pause");
                        system("cls");
                        continue;
                    }
                    system("pause");
                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    system("pause");
                    break;
                }
                default: {
                    cout<<"Brak opcji o kodzie "<<option<<"\n";
                    system("pause");
                    break;
                }
            }

        } else if (user->czyStudent){           // STUDENT
            cout << "0 - Wyloguj sie\n1 - Narzedzia dydaktyczne\n2 - Przedmioty\n3 - Wyswietl profil\n9 - Wyjdz z programu\n\n";
            cout<<"------------------------------\n\n";
            cin >> option;
            system("cls");
            switch(option){
                case '0':{
                    user->wylogujSie();
                    user = NULL;
                    system("pause");
                    break;
                }
                case '1':{
                    cout<<"\nN A R Z E D Z I A   D Y D A K T Y C Z N E\n\n";
                    cout<<"------------------------------\n\n";
                    cout<<"Dostepne narzedzia dydaktyczne:\n";
                    uczelnia->wyswietlNarzedzia();
                    cout<<"\n------------------------------\n\n";
                    cout << "Wpisz nazwe wybranego oprogramowania: ";
                    cin >> wybor;
                    cout<<"\n------------------------------\n\n";
                    uczelnia->skorzystajZNarzedzia(wybor);
                    cout<<"\n";
                    system("pause");
                    break;
                }
                case '2':{
                    cout<<"\nP R Z E D M I O T Y\n\n";
                    cout<<"------------------------------\n\n";
                    map<Przedmiot*, vector<int>>* s_przedmioty = ((Student*)user)->getPrzedmioty();
                    if(s_przedmioty->empty()){
                        cout << "Nie znaleziono przedmiotow!\n";
                        system("pause");
                        break;
                    } else {
                        cout << "Wybierz przedmiot:\n";
                        for(auto x: *s_przedmioty){
                            cout << "\t> " << x.first->getNazwa() << "\n";
                        }
                        cout<<"\n------------------------------\n\n";
                        cin >> wybor;
                        Przedmiot* przedmiot = NULL;
                        vector<int> oceny;
                        for(auto x: *s_przedmioty){
                            if(x.first->getNazwa() == wybor){
                                przedmiot = x.first;
                                oceny = x.second;
                                break;
                            }
                        }
                        if(przedmiot == NULL){
                            cout << "Nie znaleziono przedmiotu o takiej nazwie!\n\n";
                            system("pause");
                            break;
                        }
                        system("cls");
                        cout << "\nPrzedmiot: " << przedmiot->getNazwa() << "\n\n";
                        cout<<"------------------------------\n\n";
                        cout << "1 - Materialy\n2 - Oceny\n\n";
                        cout<<"------------------------------\n\n";
                        char choice;
                        cin >> choice;
                        system("cls");
                        switch(choice) {
                            case '1': {
                                cout<<"\nM A T E R I A L Y\n\n";
                                cout<<"------------------------------\n\n";
                                cout<<"Linki:\n";
                                przedmiot->wyswietlMaterialy();
                                cout<<"\n";
                                system("pause");
                                break;
                            }
                            case '2': {
                                cout<<"\nO C E N Y\n\n";
                                cout<<"------------------------------\n\n";
                                cout << "Oceny z przedmiotu " << przedmiot->getNazwa() << ": ";
                                for(auto it = oceny.begin(); it != oceny.end(); ++it){
                                    cout << *it;
                                    if(it != oceny.end()-1){
                                        cout << ", ";
                                    }
                                }
                                cout << "\n\n";
                                system("pause");
                                break;
                            }
                            default: {
                                cout<<"Brak opcji o kodzie "<<option<<"\n";
                                system("pause");
                                break;
                            }
                        }
                    break;
                    }
                }
                case '3': {
                    system("cls");
                    cout<<"\nP R O F I L\n\n";
                    cout<<"------------------------------\n\n";
                    ((Student*)user)->sprawdzDane();
                    cout<<"\n";
                    system("pause");
                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    system("pause");
                    break;
                }
                default: {
                    cout<<"Brak opcji o kodzie "<<option<<"\n";
                    system("pause");
                    break;
                }
            }

        } else {                                // WYKLADOWCA
            cout << "0 - Wyloguj sie\n1 - Narzedzia dydaktyczne\n2 - Przedmioty\n3 - Wyswietl profil\n9 - Wyjdz z programu\n\n";
            cout<<"------------------------------\n\n";
            cin >> option;
            system("cls");
            switch(option){
                case '0':{
                    user->wylogujSie();
                    user = NULL;
                    system("pause");
                    break;
                }
                case '1':{
                    cout<<"\nN A R Z E D Z I A   D Y D A K T Y C Z N E\n\n";
                    cout<<"------------------------------\n\n";
                    cout<<"Dostepne oprogramowanie:\n";
                    uczelnia->wyswietlNarzedzia();
                    cout<<"\n------------------------------\n\n";
                    cout << "Wpisz nazwe wybranego oprogramowania: ";
                    cin >> wybor;
                    cout<<"\n------------------------------\n\n";
                    uczelnia->skorzystajZNarzedzia(wybor);
                    cout<<"\n";
                    system("pause");
                    break;
                }
                case '2': {
                    cout<<"\nP R Z E D M I O T Y\n\n";
                    cout<<"------------------------------\n\n";
                    if(((Wykladowca*)user)->getPrzedmioty()->empty()){
                        cout << "Nie znaleziono przedmiotow!\n";
                    } else {
                        cout<<"Prowadzone przedmioty:\n";
                        ((Wykladowca*)user)->wyswietlPrzedmioty();
                    }
                    cout<<"\n------------------------------\n\n";

                    cout << "Wybierz przedmiot, lub wpisz nazwe dla nowego przedmiotu:\n";
                    cin >> wybor;
                    system("cls");

                    Przedmiot* przedmiot = NULL;
                    for(auto x: *((Wykladowca*)user)->getPrzedmioty()){
                        if(x->getNazwa() == wybor){
                            przedmiot = x;
                            break;
                        }
                    }

                    if(przedmiot == NULL){
                        ((Wykladowca*)user)->dodajPrzedmiot(wybor);
                        cout << "Dodano nowy przedmiot \"" << wybor << "\"\n";
                        przedmiot = ((Wykladowca*)user)->getPrzedmioty()->back();
                        system("pause");
                    }

                    system("cls");
                    cout << "\nPrzedmiot: " << przedmiot->getNazwa() << "\n\n";
                    cout<<"------------------------------\n\n";
                    cout<<"1 - Dodaj materialy\n2 - Usun ostatni material\n3 - Dodaj ocene\n4 - Usun ostatnia ocene\n5 - Dodaj studenta do przedmiotu\n6 - Usun studenta z przedmiotu\n7 - Usun przedmiot\n0 - Powrot do ekranu domowego\n\n";
                    cout<<"------------------------------\n\n";
                    cin>>option;
                    system("cls");
                    switch(option) {
                        case '0': {
                            break;
                        }
                        case '1': {
                            cout<<"\nD O D A J   M A T E R I A L Y\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Materialy do przedmiotu:\n";
                            przedmiot->wyswietlMaterialy();
                            cout<<"\n------------------------------\n\n";
                            cout<<"Podaj link do materialu: ";
                            string link;
                            cin>>link;
                            ((Wykladowca*)user)->dodajMaterial(przedmiot,link);
                            break;
                        }
                        case '2': {
                            cout<<"\nU S U N   O S T A T N I   M A T E R I A L\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Materialy do przedmiotu:\n";
                            przedmiot->wyswietlMaterialy();
                            cout<<"\n------------------------------\n\n";
                            ((Wykladowca*)user)->usunMaterial(przedmiot);
                            break;
                        }
                        case '3': {
                            cout<<"\nD O D A J   O C E N E\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Studenci zapisani na przedmiot i ich oceny:\n";
                            przedmiot->wyswietlStudentowIOceny(przedmiot->getNazwa());
                            cout<<"\n------------------------------\n\n";
                            int ocena;
                            string nrAlbumu;
                            cout<<"Podaj numer albumu studenta: ";
                            cin>>nrAlbumu;
                            bool err = true;
                            for(Student* x: *(przedmiot->getStudenci())){
                                if(x->getNrAlbumu() == nrAlbumu){
                                    err = false;
                                    break;
                                }
                            }
                            if(err) {
                                cout << "Nie ma takiego studenta!\n";
                                break;
                            }

                            cout<<"Podaj ocene: ";
                            cin>>ocena;
                            while(ocena < 2 || ocena > 5){
                                cout << "Zla ocena, wpisz poprawna: ";
                                cin>>ocena;
                            }
                            ((Wykladowca*)user)->dodajOcene(przedmiot,nrAlbumu,ocena);
                            break;
                        }
                        case '4': {
                            cout<<"\nU S U N  O S T A T N I A  O C E N E\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Studenci zapisani na przedmiot i ich oceny:\n";
                            przedmiot->wyswietlStudentowIOceny(przedmiot->getNazwa());
                            cout<<"\n------------------------------\n\n";
                            string nrAlbumu;
                            cout<<"Podaj numer albumu studenta: ";
                            cin>>nrAlbumu;
                            bool err = true;
                            for(Student* x: *(przedmiot->getStudenci())){
                                if(x->getNrAlbumu() == nrAlbumu){
                                    err = false;
                                    break;
                                }
                            }
                            if(err) {
                                cout << "Nie ma takiego studenta!\n";
                                break;
                            }
                            ((Wykladowca*)user)->usunOcene(przedmiot,nrAlbumu);
                            break;
                        }
                        case '5': {
                            cout<<"\nD O D A J   S T U D E N T A   D O   P R Z E D M I O T U\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Studenci zapisani na "<<przedmiot->getNazwa()<<":\n";
                            przedmiot->wyswietlStudentow();
                            cout<<"\n------------------------------\n\n";
                            cout<<"Uzytkownicy zarejestrowani w systemie:\n";
                            uczelnia->wyswietlUzytkownikow();
                            cout<<"\n------------------------------\n\n";
                            string nrAlbumu;
                            cout<<"Podaj numer albumu studenta: ";
                            cin>>nrAlbumu;
                            bool err = true;
                            for(Uzytkownik* x: *(uczelnia->getUzytkownicy())){
                                if(x->czyStudent) {
                                    if(((Student*)x)->getNrAlbumu() == nrAlbumu){
                                        err = false;
                                        break;
                                    }
                                }
                            }
                            if(err) {
                                cout << "Nie ma takiego studenta!\n";
                                break;
                            }

                            for(Student* x: *(przedmiot->getStudenci())){
                                if(x->getNrAlbumu() == nrAlbumu){
                                    cout<<"Student jest juz zapisany na ten przedmiot!\n";
                                    err = true;
                                    break;
                                }
                            }
                            if(err) {
                                break;
                            }

                            ((Wykladowca*)user)->dodajStudentaDoPrzedmiotu(przedmiot,uczelnia->znajdzStudenta(nrAlbumu));
                            break;
                        }
                        case '6': {
                            cout<<"\nU S U N   S T U D E N T A   Z   P R Z E D M I O T U\n\n";
                            cout<<"------------------------------\n\n";
                            cout<<"Studenci zapisani na "<<przedmiot->getNazwa()<<":\n";
                            przedmiot->wyswietlStudentow();
                            cout<<"\n------------------------------\n\n";
                            string nrAlbumu;
                            cout<<"Podaj numer albumu studenta: ";
                            cin>>nrAlbumu;
                            bool err = true;
                            for(Student* x: *(przedmiot->getStudenci())){
                                if(x->getNrAlbumu() == nrAlbumu){
                                    err = false;
                                    break;
                                }
                            }
                            if(err) {
                                cout << "Nie ma takiego studenta zapisanego na ten przedmiot!\n";
                                break;
                            }
                            ((Wykladowca*)user)->usunStudentaZPrzedmiotu(przedmiot,uczelnia->znajdzStudenta(nrAlbumu));
                            break;
                        }
                        case '7': {
                            cout<<"\nU S U N   P R Z E D M I O T\n\n";
                            cout<<"------------------------------\n\n";
                            string conf;
                            cout<<"Potwierdz usuniecie przedmiotu "<<przedmiot->getNazwa()<<" komenda \"USUN\": ";
                            cin>>conf;
                            if(conf == "USUN") {
                                ((Wykladowca*)user)->usunPrzedmiot(przedmiot);
                            } else {
                                cout<<"Niepoprawna opcja, powrot do ekranu glownego...\n\n";
                            }
                            break;
                        }
                        default: {
                            cout<<"Brak opcji o kodzie "<<option<<"\n";
                            break;
                        }
                    }
                    system("pause");
                    break;
                }
                case '3': {
                    system("cls");
                    cout<<"\nP R O F I L\n\n";
                    cout<<"------------------------------\n\n";
                    ((Wykladowca*)user)->sprawdzDane();
                    cout<<"\n";
                    system("pause");
                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    system("pause");
                    break;
                }
                default: {
                    cout<<"Brak opcji o kodzie "<<option<<"\n";
                    system("pause");
                    break;
                }
            }
        }
        system("cls");
    }

    // Destruktor klasy Uczelnia, usuwa wszystkie obiekty typu Uzytkownik (Student, Wykladowca)
    // Destruktor klasy Wykladowca usuwa rowniez wszystkie obiekty typu Przedmiot
    // W rezultacie destruktor klasy Uczelnia usuwa wszystkie obiekty sciśle powiazane z obiektem uczelnia.

    delete excel;
    delete word;
    delete uczelnia;

    return 0;
}
