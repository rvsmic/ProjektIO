#include <iostream>
#include "Uczelnia.h"
#include "Uzytkownik.h"
#include "Student.h"
#include "Wykladowca.h"
#include "Przedmiot.h"

using namespace std;

int main()
{
    Uczelnia* uczelnia = new Uczelnia("UMCS");

    Narzedzie* excel = new Narzedzie("Excel", "www.excel.com");
    Narzedzie* word = new Narzedzie("Word", "www.word.com");

    uczelnia->dodajNarzedzie(excel);
    uczelnia->dodajNarzedzie(word);

    bool EXIT_FLAG = false;

    cout << "Witaj na stronie uczelni " << uczelnia->getNazwa() << "!\n";

    Uzytkownik* user = NULL;

    char option = 0;

    string login, haslo;

    bool czyStudent = false;

    while(!EXIT_FLAG){
        if(user == NULL){                       // WYLOGOWANY
            cin >> option;

            switch(option){
                case '1':{                  // LOGOWANIE

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

                    cin >> login;
                    cin >> haslo;

                    user = uczelnia->logowanie(login, haslo, czyStudent);
                    if(user == NULL){
                        continue;
                    }

                    break;
                }
                case '2':{                  // REJESTRACJA

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

                    cin >> login;
                    cin >> haslo;

                    user = uczelnia->rejestracja(login, haslo, czyStudent);
                    if(user == NULL){
                        continue;
                    }

                    break;
                }
            }

        } else if (user->czyStudent){           // STUDENT



        } else {                                // WYKLADOWCA



        }
    }
}
