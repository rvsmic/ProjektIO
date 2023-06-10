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

Przedmiot::~Przedmiot() {
    cout << "Usunieto obiekt klasy " << "Przedmiot!\n";
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

void Przedmiot::dodajMaterial(string link) {
    materialy.push_back(link);
    cout<<"Pomyslnie dodano material!\n";
}

void Przedmiot::usunMaterial() {
    if(!materialy.empty()) {
        materialy.pop_back();
        cout<<"Pomyslnie usunieto ostatni material!\n";
        return;
    }
    cout << "Brak materialow w bazie!\n";
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
    cout<<"Nie ma takiego studenta!\n";
    return nullptr;
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

vector <string>* Przedmiot::getMaterialy(){
    return &materialy;
}

vector <Student*>* Przedmiot::getStudenci(){
    return &studenci;
}
