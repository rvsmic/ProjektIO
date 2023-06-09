#include <iostream>
#include "Uczelnia.h"
#include "Uzytkownik.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Przedmiot.h"
#include <windows.h>
#include <conio.h>

using namespace std;

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
        cout<<"\nS T R O N A   D O M O W A\n\n";
        cout << "Wybierz opcje:\n";
        if(user == NULL){                       // WYLOGOWANY

            cout << "1 - Zaloguj sie\n2 - Zarejestruj sie\n9 - Wyjdz z programu\n";
            cin >> option;
            system("cls");

            switch(option){
                case '1':{                  // LOGOWANIE
                    cout<<"\nL O G O W A N I E\n\n";
                    cout<<"1 - Logowanie dla studenta\n2 - Logowanie dla wykladowcy\n";
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
                    if(error) {
                        error = false;
                        break;
                    }
                    cout<<"Podaj login: ";
                    cin >> login;
                    cout<<"Podaj haslo: ";
                    cin >> haslo;

                    user = uczelnia->logowanie(login, haslo, czyStudent);
                    if(user != NULL){
                        break;
                    } else {
                        cout << "Czy chcesz sie zarejestrowac?\n1 - Tak\n2 - Nie\n";
                        cin >> option;
                        if(option == '1'){
                            cout<<"Przejscie do rejestracji...\n";
                            system("pause");
                            system("cls");
                        } else if (option == '2'){
                            cout<<"Powrot do ekranu poczatkowego...\n";
                            system("pause");
                            break;
                        } else {
                            cout<<"Bledna opcja, powrot do ekranu poczatkowego...\n";
                            system("pause");
                            break;
                        }
                    }
                }
                case '2':{ // REJESTRACJA
                    cout<<"\nR E J E S T R A C J A\n\n";
                    cout<<"1 - Rejestracja dla studenta\n2 - Rejestracja dla wykladowcy\n";
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
                            cout<<"Brak opcji o kodzie "<<option<<"\n";
                            error = true;
                            system("pause");
                            break;
                        }
                    }
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
            cout << "0 - Wyloguj sie\n1 - Narzedzia dydaktyczne\n2 - Przedmioty\n9 - Wyjdz z programu\n";
            cin >> option;
            system("cls");
            switch(option){
                case '0':{
                    user->wylogujSie();
                    user = NULL;
                    break;
                }
                case '1':{
                    cout<<"\nN A R Z E D Z I A   D Y D A K T Y C Z N E\n\n";
                    uczelnia->wyswietlNarzedzia();
                    cout << "Wpisz nazwe wybranego oprogramowania: ";
                    cin >> wybor;
                    uczelnia->skorzystajZNarzedzia(wybor);
                    system("pause");
                    break;
                }
                case '2':{  // NIEDOKONCZONE
                    cout<<"\nP R Z E D M I O T Y\n\n";
                    map<Przedmiot*, vector<int>>* s_przedmioty = ((Student*)user)->getPrzedmioty();
                    if(s_przedmioty->empty()){
                        cout << "Nie znaleziono przedmiotów!\n";
                        system("pause");
                        break;
                    } else {
                        cout << "Wybierz przedmiot:\n";
                        for(auto x: *s_przedmioty){
                            cout << "\t> " << x.first->getNazwa() << "\n";
                        }
                        cin >> wybor;
                        Przedmiot* przedmiot = NULL;
                        vector<int>* oceny = NULL;
                        for(auto x: *s_przedmioty){
                            if(x.first->getNazwa() == wybor){
                                przedmiot = x.first;
                                oceny = &(x.second);
                                break;
                            }
                        }
                        if(przedmiot == NULL){
                            cout << "Nie znaleziono przedmiotu o takiej nazwie!\n";
                            system("pause");
                            break;
                        }
                        system("cls");
                        cout << "Przedmiot: " << przedmiot->getNazwa() << "\n";
                        cout << "1 - Sprawdz materialy\n2 - Sprawdz oceny\n";
                        char choice;
                        cin >> choice;
                        system("cls");
                        switch(choice) {
                            case '1': {
                                przedmiot->wyswietlMaterialy();
                                system("pause");
                                break;
                            }
                            case '2': {
                                cout << "Oceny: ";
                                for(int o: *oceny){
                                    cout << o << ", ";
                                }
                                cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                    break;
                    }
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
            cout << "0 - Wyloguj sie\n1 - Narzedzia dydaktyczne\n2 - Przedmioty\n9 - Wyjdz z programu\n";
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
                    cout<<"Dostepne oprogramowanie:\n";
                    uczelnia->wyswietlNarzedzia();
                    cout << "Wpisz nazwe wybranego oprogramowania: ";
                    cin >> wybor;
                    uczelnia->skorzystajZNarzedzia(wybor);
                    system("pause");
                    break;
                }
                case '2': {
                    cout<<"\nP R Z E D M I O T Y\n\n";
                    cout << "1 - Dodaj przedmiot\n2 - Prowadzone przedmioty\n";
                    cin >> option;
                    system("cls");
                    switch(option) {
                        case '1': {
                            cout<<"\nD O D A J   P R Z E D M I O T\n\n";
                            cout << "Podaj nazwe nowego przedmiotu: ";
                            cin >> wybor;
                            bool tmp = true;
                            for(Przedmiot* x: *((Wykladowca*)user)->getPrzedmioty()){
                                if(x->getNazwa() == wybor){
                                    cout << "Przedmiot o tej nazwie juz istnieje!\n"; // cos tam
                                    system("pause");
                                    tmp = false;
                                    break;
                                }
                            }
                            if(tmp){
                                ((Wykladowca*)user)->dodajPrzedmiot(wybor);
                                cout<<"Pomyslnie dodano przedmiot \""<<wybor<<"\"\n";
                            }
                            system("pause");
                            break;
                        }
                        case '2': {
                            cout<<"\nP R O W A D Z O N E   P R Z E D M I O T Y\n\n";
                            cout<<"Aktualnie prowadzone przedmioty:\n";
                            ((Wykladowca*)user)->wyswietlPrzedmioty();
                            vector <Przedmiot*>* przedmioty = ((Wykladowca*)user)->getPrzedmioty();
                            if(przedmioty->empty()) {
                                system("pause");
                                break;
                            }
                            cout<<"\n";
                            cout << "Wpisz nazwe wybranego przedmiotu: ";
                            cin >> wybor;
                            Przedmiot* przedmiot = NULL;
                            for(Przedmiot* x: *przedmioty){
                                if(x->getNazwa() == wybor){
                                    przedmiot = x;
                                    break;
                                }
                            }
                            if(przedmiot == NULL) {
                                cout << "Nie ma takiego przedmiotu\n";
                                system("pause");
                                break;
                            }

                            system("cls");
                            cout << "Przedmiot: " << przedmiot->getNazwa() << "\n";
                            cout<<"1 - Dodaj materialy\n2 - Dodaj ocene\n3 - Usun ocene\n4 - Dodaj studenta do przedmiotu\n5 - Usun studenta z przedmiotu\n0 - Powrot do ekranu domowego\n";
                            cin>>option;
                            system("cls");
                            switch(option) {
                                case '0': {
                                    break;
                                }
                                case '1': {
                                    cout<<"\nD O D A J   M A T E R I A L Y\n\n";
                                    cout<<"Materialy do przedmiotu:\n";
                                    przedmiot->wyswietlMaterialy();
                                    cout<<"Podaj link do materialu: ";
                                    string link;
                                    cin>>link;
                                    ((Wykladowca*)user)->dodajMaterialy(przedmiot,link);
                                    cout<<"Pomyslnie dodano material\n";
                                    break;
                                }
                                case '2': {
                                    cout<<"\nD O D A J   O C E N E\n\n";
                                    cout<<"Studenci zapisani na przedmiot i ich oceny:\n";
                                    przedmiot->wyswietlStudentowIOceny(przedmiot->getNazwa());
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
                                case '3': {
                                    cout<<"\nU S U N   O C E N E\n\n";
                                    cout<<"Studenci zapisani na przedmiot i ich oceny:\n";
                                    przedmiot->wyswietlStudentowIOceny(przedmiot->getNazwa());
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
                                    ((Wykladowca*)user)->usunOcene(przedmiot,nrAlbumu);
                                    break;
                                }
                                case '4': {
                                    cout<<"\nD O D A J   S T U D E N T A   D O   P R Z E D M I O T U\n\n";
                                    cout<<"Studenci zapisani na "<<przedmiot->getNazwa()<<":\n";
                                    przedmiot->wyswietlStudentow();
                                    cout<<"Uzytkownicy zarejestrowani w systemie:\n";
                                    uczelnia->wyswietlUzytkownikow();
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
                                        system("pause");
                                        break;
                                    }
                                    ((Wykladowca*)user)->dodajStudentaDoPrzedmiotu(przedmiot,uczelnia->znajdzStudenta(nrAlbumu));
                                    cout<<"Pomyslnie dodano studenta\n";
                                    break;
                                }
                                case '5': {
                                    cout<<"\nU S U N   S T U D E N T A   Z   P R Z E D M I O T U\n\n";
                                    cout<<"Studenci zapisani na "<<przedmiot->getNazwa()<<":\n";
                                    przedmiot->wyswietlStudentow();
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
                                        system("pause");
                                        break;
                                    }
                                    //((Wykladowca*)user)->usunStudentaZPrzedmiotu(przedmiot,uczelnia->znajdzStudenta(nrAlbumu));
                                    cout<<"Pomyslnie usunieto studenta\n";
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
                        default: {
                            cout<<"Brak opcji o kodzie "<<option<<"\n";
                            system("pause");
                            break;
                        }
                    }
                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    system("pause");
                    break;
                }
                // STUDENT MA ZLE EKRAN SPRAWDZANAI OCEN ZE SCENARIUSZEM, USUWANIE OCEN, DODAWANIE MATERIALOW USUWANIE MATERIALOW STUDENT PWN ZJEBANY RESZYA
            }
        }
        system("cls");
    }
    return 0;
}
