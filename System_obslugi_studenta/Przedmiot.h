//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Przedmiot.h
//  @ Date : 24.05.2023
//  @ Author :
//
//


#if !defined(_PRZEDMIOT_H)
#define _PRZEDMIOT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Wykladowca.h"
#include "Student.h"

class Student;

class Wykladowca;

class Przedmiot {
public:
	Przedmiot(string nazwa, Wykladowca* wykladowca);
	void setNazwa(string nazwa);
	string getNazwa();
	void setWykladowca(Wykladowca* wykladowca);
	Wykladowca* getWykladowca();
	void dodajMaterialy(string link);
	void usunMaterialy(string link);
	void wyswietlMaterialy();
	void dodajStudenta(Student* student);
	void usunStudenta(Student* student);
	Student* znajdzStudenta(string nrAlbumu);
	void wyswietlStudentow();
	void wyswietlStudentowIOceny(string przedmiot);
private:
	string nazwa;
	Wykladowca* wykladowca;
	vector <Student*> studenci;
	vector <string> materialy;
};

#endif  //_PRZEDMIOT_H