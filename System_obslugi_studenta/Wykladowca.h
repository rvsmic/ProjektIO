//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Wykladowca.h
//  @ Date : 24.05.2023
//  @ Author :
//
//


#if !defined(_WYKLADOWCA_H)
#define _WYKLADOWCA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Uzytkownik.h"
#include "Przedmiot.h"
#include "Student.h"

class Student;
class Przedmiot;

class Wykladowca : public Uzytkownik {
public:
	Wykladowca(string login, string haslo, string identyfikator);
	void setIdentyfikator(string identyfikator);
	string getIdentyfikator();
	void dodajPrzedmiot(string nazwa);
	void usunPrzedmiot(string nazwa);
	void dodajMaterialy(Przedmiot* przedmiot, string link);
	void usunMaterialy(string przedmiot, string link);
	void dodajOcene(Przedmiot* przedmiot, string nrAlbumuStudenta, int ocena);
	void usunOcene(Przedmiot* przedmiot, string nrAlbumuStudenta);
	void dodajStudentaDoPrzedmiotu(Przedmiot* przedmiot, Student* student);
	void usunStudentaZPrzedmiotu(string przedmiot, Student* student);
	void wyswietlPrzedmioty();
	void wyswietlPrzedmiotyZeStudentami();
	void wyswietlPrzedmiotyZMaterialami();
	void wyswietlPrzedmiotyZeStudentamiIOcenami();
	vector <Przedmiot*>* getPrzedmioty();
private:
	string identyfikator;
	vector <Przedmiot*> przedmioty;
};

#endif  //_WYKLADOWCA_H
