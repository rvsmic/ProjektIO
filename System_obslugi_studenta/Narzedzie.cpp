//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Narzedzie.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//


#include "Narzedzie.h"

Narzedzie::Narzedzie(string nazwa, string link) {
    cout << "Stworzono obiekt klasy " << "Narzedzie!\n";
    this->nazwa = nazwa;
    this->link = link;
}

Narzedzie::~Narzedzie() {
    cout << "Usunieto obiekt klasy " << "Narzedzie!\n";
}

void Narzedzie::setNazwa(string nazwa) {
    this->nazwa = nazwa;
}

string Narzedzie::getNazwa() {
    return this->nazwa;
}

void Narzedzie::setLink(string link) {
    this->link = link;
}

string Narzedzie::getLink() {
    return this->link;
}

void Narzedzie::uruchomNarzedzie() {
    cout << "Uruchomiono narzedzie: " << nazwa << "\n";
    cout << "Link: " << link << "\n";
}

