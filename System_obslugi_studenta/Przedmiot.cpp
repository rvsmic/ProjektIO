//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Przedmiot.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//


#include "Przedmiot.h"

Przedmiot::Przedmiot(string nazwa, Wykladowca* wykladowca) {
    cout << "Stworzono obiekt klasy " << "Przedmiot!\n";
    this->nazwa = nazwa;
    this->wykladowca = wykladowca;
}

void Przedmiot::setNazwa(string nazwa) {
    this->nazwa = nazwa;
}

string Przedmiot::getNazwa() {
    return this->nazwa;
}

void Przedmiot::setWykladowca(Wykladowca* wykladowca) {
    this->wykladowca = wykladowca;
}

Wykladowca* Przedmiot::getWykladowca() {
    return this->wykladowca;
}

void Przedmiot::dodajMaterialy(string link) {
    materialy.push_back(link);
}

void Przedmiot::usunMaterialy(string link) {
    for(auto x = materialy.begin(); x != materialy.end(); ++x){
        if((*x) == link){
            materialy.erase(x);
            return;
        }
    }
    cout << "Nie znaleziono takiego linku!\n";
}

void Przedmiot::wyswietlMaterialy() {
    for(auto x = materialy.begin(); x != materialy.end(); ++x){
        cout<<"\t> "<<(*x)<<"\n";
    }
}

void Przedmiot::dodajStudenta(Student* student) {
    studenci.push_back(student);
}

void Przedmiot::usunStudenta(Student* student) {
    for(auto x = studenci.begin(); x != studenci.end(); ++x){
        if((*x)->getNrAlbumu() == student->getNrAlbumu()){
            studenci.erase(x);
            return;
        }
    }
}

Student* Przedmiot::znajdzStudenta(string nrAlbumu){
    for(auto x = studenci.begin(); x != studenci.end(); ++x){
        if((*x)->getNrAlbumu() == nrAlbumu){
            return *x;
        }
    }
}

void Przedmiot::wyswietlStudentow() {
    for(auto x = studenci.begin(); x != studenci.end(); ++x){
        cout<<"\t> nrAlbumu: "<<(*x)->getNrAlbumu()<<", Login: "<<(*x)->getLogin()<<"\n";
    }
}

void Przedmiot::wyswietlStudentowIOceny(string przedmiot) {
    for(auto x = studenci.begin(); x != studenci.end(); ++x){
        cout<<"\t> nrAlbumu: "<<(*x)->getNrAlbumu()<<", Login: "<<(*x)->getLogin()<<", Oceny: ";
        (*x)->sprawdzOceny((przedmiot));
        cout<<"\n";
    }
}