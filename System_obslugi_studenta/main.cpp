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
            }

        } else if (user->czyStudent){           // STUDENT
            cout << "0 - Wyloguj sie\n1 - Narzedzia dydaktyczne\n2 - Przedmioty\n9 - Wyjdz z programu\n";
            cin >> option;
            switch(option){
                case '0':{
                    user->wylogujSie();
                    user = NULL;
                    break;
                }
                case '1':{
                    uczelnia->wyswietlNarzedzia();
                    cout << "Wpisz nazwe wybranego oprogramowania: ";
                    cin >> wybor;
                    uczelnia->skorzystajZNarzedzia(wybor);
                    system("pause");
                    break;
                }
                case '2':{  // NIEDOKONCZONE
                    cout << "Wybierz przedmiot: ";
                    ((Student*)user)->wyswietlPrzedmioty();
                    cin >> wybor;
                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
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
                    cout << "1 - Dodaj przedmiot\n2 - Uczone przedmioty\n";
                    char choice;
                    cin >> choice;
                    system("cls");
                    switch(choice) {
                        case '1': {
                            cout<<"\nD O D A J   P R Z E D M I O T\n\n";
                            string nazwa;
                            cout << "Podaj nazwe nowego przedmiotu: ";
                            cin >> nazwa;
                            // sprawdzenie czy nie duplikat?
                            ((Wykladowca*)user)->dodajPrzedmiot(nazwa);
                            cout<<"Pomyslnie dodano przedmiot \""<<nazwa<<"\"\n";
                            system("pause");
                            break;
                        }
                        case '2': {
                            cout<<"\nU C Z O N E   P R Z E D M I O T Y\n\n";
                            cout<<"Aktualnie prowadzone przedmioty:\n";
                            ((Wykladowca*)user)->wyswietlPrzedmioty();
                            cout<<"\n";

                            // wyswietl oceny + wyswietl materialy ????

                            cout<<"1 - Dodaj materialy\n2 - Dodaj ocene\n0 - Powrot do ekranu domowego\n";
                            char sub_choice;
                            cin>>sub_choice;
                            system("cls");
                            switch(sub_choice) {
                                case '1': {
                                    cout<<"\nD O D A J   M A T E R I A L Y\n\n";
                                    cout<<"Podaj nazwe przedmiotu: ";
                                    string przedmiot;
                                    cin>>przedmiot;
                                    cout<<"Podaj link do materialu: ";
                                    string link;
                                    cin>>link;
                                    ((Wykladowca*)user)->dodajMaterialy(przedmiot,link);
                                    cout<<"Pomyslnie dodano material\n";
                                    break;
                                }
                                case '2': {
                                    cout<<"\nD O D A J   O C E N E\n\n";
                                    // WYSWIETLIC STUDENTOW
                                    int ocena;
                                    cout<<"DO ZROBIENIA!!!\n";
                                    break;
                                }
                            }
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
            }
        }
        system("cls");
    }
    return 0;
}
