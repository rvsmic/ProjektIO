//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Student.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//


#include "Student.h"

Student::Student(string login, string haslo, string nrAlbumu) {
    cout << "Stworzono obiekt klasy " << "Student!\n";
    this->login = login;
    this->haslo = haslo;
    this->nrAlbumu = nrAlbumu;
    this->czyStudent = true;
}

void Student::setNrAlbumu(string numer) {
    this->nrAlbumu = numer;
}

string Student::getNrAlbumu() {
    return this->nrAlbumu;
}

void Student::sprawdzOceny(string przedmiot) {
    for(auto it = oceny.begin(); it != oceny.end(); ++it){
        if((*it).first->getNazwa() == przedmiot){
            cout << "Oceny z przedmiotu " << przedmiot << ":\n";
            for(auto x: (*it).second){
                cout << x << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "Nie znaleziono przedmiotu!\n";
}

void Student::sprawdzMaterialy(string przedmiot) {
    for(auto it = oceny.begin(); it != oceny.end(); ++it){
        if((*it).first->getNazwa() == przedmiot){
            cout << "Materialy z przedmiotu " << przedmiot << ":\n";
            (*it).first->wyswietlMaterialy();
            cout << "\n";
            return;
        }
    }
    cout << "Nie znaleziono przedmiotu!\n";
}

void Student::dodajOcene(Przedmiot* przedmiot, int ocena) {
    try{
        vector<int> tmp = oceny.at(przedmiot);
        if(ocena != -1){
            tmp.push_back(ocena);
        }
    }catch(out_of_range){
        vector <int> tmp;
        oceny[przedmiot] = tmp;
        if(ocena != -1){
            tmp.push_back(ocena);
        }
    }
}

void Student::usunOcene(Przedmiot* przedmiot) {
    try{
        vector<int> tmp = oceny.at(przedmiot);
        tmp.pop_back();
    }catch(out_of_range){
        cout << "Nie znaleziono przedmiotu!";
    }
}

void Student::wyswietlPrzedmioty(){
    for(auto x: oceny){
        cout << (x.first)->getNazwa() << "\n";
    }
}

