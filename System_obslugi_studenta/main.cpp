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

    while(!EXIT_FLAG){
        cout << "Witaj na stronie uczelni " << uczelnia->getNazwa() << "!\n";
        cout << "Wybierz opcje:\n";
        if(user == NULL){                       // WYLOGOWANY

            cout << "1 - Zaloguj sie\n2 - Zarejestruj sie\n9 - Wyjdz z programu\n";
            cin >> option;

            switch(option){
                case '1':{                  // LOGOWANIE
                    cout<<"1 - Logowanie dla studenta\n2 - Logowanie dla wykladowcy\n";
                    cin >> option;

                    switch(option){
                        case '1':{
                            czyStudent = true;
                            break;
                        }
                        case '2':{
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
                        } else if (option == '2'){
                            cout<<"Powrot do ekranu poczatkowego\n";
                            break;
                        } else {
                            cout<<"Bledna opcja, powrot do ekranu poczatkowego\n";
                            break;
                        }
                    }
                }
                case '2':{ // REJESTRACJA
                    cout<<"1 - Rejestracja dla studenta\n2 - Rejestracja dla wykladowcy\n";
                    cin >> option;

                    switch(option){
                        case '1':{
                            czyStudent = true;
                            break;
                        }
                        case '2':{
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

                    break;
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
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
                case '2':{
                    cout << "Wybierz przedmiot: ";
                    ((Student*)user)->wyswietlPrzedmioty();
                }
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    break;
                }
            }

        } else {                                // WYKLADOWCA
            cout << "0 - Wyloguj sie\n9 - Wyjdz z programu\n";
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
                case '9':{
                    EXIT_FLAG = true;
                    cout << "Wyjscie z programu...\n";
                    break;
                }
            }
        }
        system("cls");
    }
}
