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

	Uzytkownik* uzytkownik = uczelnia->logowanie("login1", "haslo1", false);

	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot1");
	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot2");
	((Wykladowca*)uzytkownik)->dodajPrzedmiot("Przedmiot3");

	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), (Student*)uczelnia->getUzytkownicy()->at(1));
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), (Student*)uczelnia->getUzytkownicy()->at(2));	
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), (Student*)uczelnia->getUzytkownicy()->at(1));
	((Wykladowca*)uzytkownik)->dodajStudentaDoPrzedmiotu(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), (Student*)uczelnia->getUzytkownicy()->at(2));

	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), ((Student*)uczelnia->getUzytkownicy()->at(1))->getNrAlbumu(), 5);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), ((Student*)uczelnia->getUzytkownicy()->at(1))->getNrAlbumu(), 2);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 4);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 3);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(0), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 2);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), ((Student*)uczelnia->getUzytkownicy()->at(1))->getNrAlbumu(), 3);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), ((Student*)uczelnia->getUzytkownicy()->at(1))->getNrAlbumu(), 4);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(1), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 5);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 2);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), ((Student*)uczelnia->getUzytkownicy()->at(1))->getNrAlbumu(), 3);
	((Wykladowca*)uzytkownik)->dodajOcene(((Wykladowca*)uzytkownik)->getPrzedmioty()->at(2), ((Student*)uczelnia->getUzytkownicy()->at(2))->getNrAlbumu(), 4);
	uzytkownik->wylogujSie();


	uzytkownik = uczelnia->logowanie("login2", "haslo2", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot1");
	std::cout << "\n";
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot2");
	std::cout << "\n";
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot3");
	std::cout << "\n";
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login3", "haslo3", true);
	((Student*)uzytkownik)->wyswietlPrzedmioty();
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot1");
	std::cout << "\n";
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot2");
	std::cout << "\n";
	std::cout << "Oceny: ";
	((Student*)uzytkownik)->sprawdzOceny("Przedmiot3");
	std::cout << "\n";
	uzytkownik->wylogujSie();

	
	delete uczelnia;
}

int main() {
	std::cout << "Test: Wstaw i Sprawdz oceny\n\n";

	std::cout << "test():\n\n";
	test();

	return 0;
}