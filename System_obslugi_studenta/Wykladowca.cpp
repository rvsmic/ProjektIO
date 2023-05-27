//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Wykladowca.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//


#include "Wykladowca.h"

Wykladowca::Wykladowca(string login, string haslo, string identyfikator) {
    cout << "Stworzono obiekt klasy " << "Wykladowca!\n";
    this->login = login;
    this->haslo = haslo;
    this->identyfikator = identyfikator;
    this->czyStudent = false;
}

void Wykladowca::setIdentyfikator(string identyfikator) {
    this->identyfikator = identyfikator;
}

string Wykladowca::getIdentyfikator() {
    return this->identyfikator;
}

void Wykladowca::dodajPrzedmiot(string nazwa) {
    Przedmiot* przedmiot = new Przedmiot(nazwa, this);
    this->przedmioty.push_back(przedmiot);
}

void Wykladowca::usunPrzedmiot(string nazwa) {
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == nazwa){
            przedmioty.erase(x);
            return;
        }
    }
    cout << "Nie znaleziono przedmiotu z taka nazwa!\n";
}

void Wykladowca::dodajMaterialy(string przedmiot, string link) {
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->dodajMaterialy(link);
            return;
        }
    }
}

void Wykladowca::usunMaterialy(string przedmiot, string link) {
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->usunMaterialy(link);
            return;
        }
    }
}

void Wykladowca::dodajOcene(string przedmiot, string nrAlbumu, int ocena) {
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->znajdzStudenta(nrAlbumu)->dodajOcene((*x), ocena);
            return;
        }
    }
}

void Wykladowca::usunOcene(string przedmiot, string nrAlbumu) {
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->znajdzStudenta(nrAlbumu)->usunOcene(*x);
            return;
        }
    }
}

void Wykladowca::dodajStudentaDoPrzedmiotu(string przedmiot, Student* student){
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->dodajStudenta(student);
            student->dodajOcene((*x), -1);
            return;
        }
    }
}

void Wykladowca::usunStudentaZPrzedmiotu(string przedmiot, Student* student){
    for(auto x = przedmioty.begin(); x != przedmioty.end(); x++){
        if((*x)->getNazwa() == przedmiot){
            (*x)->usunStudenta(student);
            return;
        }
    }
}

