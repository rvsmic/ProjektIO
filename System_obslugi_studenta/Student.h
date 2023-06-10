//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Student.h
//  @ Date : 24.05.2023
//  @ Author :
//
//


#if !defined(_STUDENT_H)
#define _STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cout, std::cin;
using std::string;
using std::map;

#include "Uzytkownik.h"
#include "Przedmiot.h"

class Przedmiot;

class Student : public Uzytkownik {
public:
	Student(string login, string haslo, string nrAlbumu);
	~Student();
	void setNrAlbumu(string numer);
	string getNrAlbumu();
	void sprawdzOceny(string przedmiot);
	void sprawdzMaterialy(string przedmiot);
	void dodajOcene(Przedmiot* przedmiot, int ocena);
	void usunOcene(Przedmiot* przedmiot);
	void wyswietlPrzedmioty();
	map<Przedmiot*, vector<int>>* getPrzedmioty();
	void usunZPrzedmiotu(Przedmiot* przedmiot);
private:
	string nrAlbumu;
	map <Przedmiot*,vector<int> > oceny;
};

#endif  //_STUDENT_H
