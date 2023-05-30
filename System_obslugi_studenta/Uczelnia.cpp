//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Uczelnia.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//

#include "Uczelnia.h"

Uczelnia::Uczelnia(string nazwa) {
    cout << "Stworzono obiekt klasy " << "Uczelnia!\n";
    this->nazwa = nazwa;
}

void Uczelnia::setNazwa(string nazwa) {
    this->nazwa = nazwa;
}

string Uczelnia::getNazwa() {
    return this->nazwa;
}

void Uczelnia::dodajUzytkownika(Uzytkownik* uzytkownik) {
    this->uzytkownicy.push_back(uzytkownik);
}

void Uczelnia::usunUzytkownika(string login) {
    for(auto x = uzytkownicy.begin(); x != uzytkownicy.end(); ++x){
        if((*x)->getLogin() == login){
            uzytkownicy.erase(x);
            return;
        }
    }
}

void Uczelnia::dodajNarzedzie(Narzedzie* narzedzie) {
    this->narzedzia.push_back(narzedzie);
}

void Uczelnia::usunNarzedzie(string nazwa) {
    for(auto x = narzedzia.begin(); x != narzedzia.end(); ++x){
        if((*x)->getNazwa() == nazwa){
            narzedzia.erase(x);
            return;
        }
    }
}

Uzytkownik* Uczelnia::logowanie(string login, string haslo, bool czyStudent) {
    if(uzytkownicy.empty()){
        cout << "Brak uzytkownikow!\n";
        return NULL;
    }

    //if(czyStudent) cout << "Logowanie dla studenta...\n";
    //else cout << "Logowanie dla wykladowcy...\n";

    for(auto x = uzytkownicy.begin(); x != uzytkownicy.end(); ++x){
        if((*x)->getLogin() == login && (*x)->czyStudent == czyStudent){
            if((*x)->getHaslo() == haslo){
                (*x)->zalogujSie();
                return *x;
            }
            cout << "Nieprawidlowe haslo!\n";
            return NULL;
        }
    }

    cout << "Nie znaleziono uzytkownika z takim loginem!\n";
    return NULL;
}

Uzytkownik* Uczelnia::rejestracja(string login, string haslo, bool czyStudent) {
    //if(czyStudent) cout << "Rejestracja dla studenta...\n";
    //else cout << "Rejestracja dla wykladowcy...\n";

    for(auto x = uzytkownicy.begin(); x != uzytkownicy.end(); ++x){
        if((*x)->getLogin() == login){
            cout << "Konto z podanym loginem juz istnieje!\n";
            return NULL;
        }
    }

    if(czyStudent){
        cout << "Podaj numer albumu: ";
        string nrAlbumu;
        cin >> nrAlbumu;
        Student* student = new Student(login, haslo, nrAlbumu);
        student->zalogujSie();
        uzytkownicy.push_back(student);
        return student;
    } else {
        cout << "Podaj identyfikator: ";
        string identyfikator;
        cin >> identyfikator;
        Wykladowca* wykladowca = new Wykladowca(login, haslo, identyfikator);
        wykladowca->zalogujSie();
        uzytkownicy.push_back(wykladowca);
        return wykladowca;
    }
}

void Uczelnia::skorzystajZNarzedzia(string nazwa) {
    for(auto x = narzedzia.begin(); x != narzedzia.end(); ++x){
        if((*x)->getNazwa() == nazwa){
            (*x)->uruchomNarzedzie();
            return;
        }
    }
    cout << "Nie znaleziono narzedzia!\nPowrot do ekranu poczatkowego\n";
}

Student* Uczelnia::znajdzStudenta(string nrAlbumu){
    for(auto x = uzytkownicy.begin(); x != uzytkownicy.end(); ++x){
        if((*x)->czyStudent){
            Student* tmp = (Student*)(*x);
            if(tmp->getNrAlbumu() == nrAlbumu){
                return tmp;
            }
        }
    }

    cout << "Nie znaleziono studenta z takim numerem albumu!\n";
}

void Uczelnia::wyswietlNarzedzia(){
    for(auto x = narzedzia.begin(); x != narzedzia.end(); ++x){
        cout << "\t- " << (*x)->getNazwa() << "(" << (*x)->getLink() << ")\n";
     }
}

