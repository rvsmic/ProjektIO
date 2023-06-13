#include <iostream>
#include <cassert>

#include "../Narzedzie.h"
#include "../Przedmiot.h"
#include "../Student.h"
#include "../Uczelnia.h"
#include "../Uzytkownik.h"
#include "../Wykladowca.h"

void test(){

	Uczelnia* uczelnia = new Uczelnia("Nazwa");

	uczelnia->dodajUzytkownika(new Wykladowca("login1", "haslo1", "123"));
	uczelnia->dodajUzytkownika(new Student("login2", "haslo2", "456"));
	uczelnia->dodajUzytkownika(new Student("login3", "haslo3", "789"));

	Uzytkownik* uzytkownik = uczelnia->getUzytkownicy()->at(0);

	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot1");
	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot2");
	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot3");

	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), "link 1");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), "link 2");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), "link 3");

	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), "link 4");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), "link 5");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), "link 6");

	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), "link 7");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), "link 8");
	((Wykladowca*)uzytkownik)->dodajMaterial(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), "link 9");

	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), (Student*)uczelnia->getUzytkownicy()->at(1));
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), (Student*)uczelnia->getUzytkownicy()->at(2));	
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), (Student*)uczelnia->getUzytkownicy()->at(1));
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), (Student*)uczelnia->getUzytkownicy()->at(2));


	uzytkownik = uczelnia->logowanie("login2", "haslo2", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	((Student*)uzytkownik)->sprawdzMaterialy("Przedmiot1");
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login3", "haslo3", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	((Student*)uzytkownik)->sprawdzMaterialy("Przedmiot1");
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login2", "haslo2", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	((Student*)uzytkownik)->sprawdzMaterialy("Przedmiot2");
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login3", "haslo3", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	((Student*)uzytkownik)->sprawdzMaterialy("Przedmiot3");
	uzytkownik->wylogujSie();

	
	delete uczelnia;
}

int main() {
	std::cout << "Test: Sprawdz materialy z przedmiotow\n\n";

	std::cout << "test():\n\n";
	test();

	return 0;
}