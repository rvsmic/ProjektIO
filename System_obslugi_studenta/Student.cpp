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

Student::~Student() {
    cout << "Usunieto obiekt klasy " << "Student!\n";

}

void Student::setNrAlbumu(string numer) {
    this->nrAlbumu = numer;
}

string Student::getNrAlbumu() {
    return this->nrAlbumu;
}

void Student::sprawdzOceny(string przedmiot) {
    bool brakOcen = true;
    for(auto it = oceny.begin(); it != oceny.end(); ++it){
        if((*it).first->getNazwa() == przedmiot){
            for(auto x = (*it).second.begin(); x!= (*it).second.end(); ++x){
                cout << (*x) << " ";
                brakOcen = false;
            }
            if(brakOcen) {
                cout<<"Brak ocen z przedmiotu";
            }
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
    if(ocena != -1){
        oceny[przedmiot].push_back(ocena);
    } else {
        vector <int> tmp;
        oceny[przedmiot] = tmp;
    }
}

void Student::usunOcene(Przedmiot* przedmiot) {
    if(!oceny[przedmiot].empty()) {
        oceny[przedmiot].pop_back();
        cout<<"Pomyslnie usunieto ostatnia ocene!\n";
    } else {
        cout<<"Brak ocen do usuniecia!\n";
    }
}

void Student::wyswietlPrzedmioty(){
    for(auto x: oceny){
        cout <<"\t> "<<(x.first)->getNazwa() << "\n";
    }
}

map<Przedmiot*, vector<int>>* Student::getPrzedmioty(){
    return &oceny;
}

void Student::usunZPrzedmiotu(Przedmiot* przedmiot) {
    oceny[przedmiot].clear();
    oceny.erase(przedmiot);
}

void Student::sprawdzDane() {
    cout<<"Witaj studencie!\n";
    cout<<"Login: "<<login<<"\n";
    cout<<"Nr. albumu: "<<nrAlbumu<<"\n";
}
