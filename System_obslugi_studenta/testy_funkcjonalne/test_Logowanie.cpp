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
	
	
	uczelnia->dodajUzytkownika(new Student("login1", "haslo1", "123"));
	uczelnia->dodajUzytkownika(new Student("login2", "haslo2", "456"));
	uczelnia->dodajUzytkownika(new Student("login3", "haslo3", "789"));
	uczelnia->dodajUzytkownika(new Wykladowca("login4", "haslo4", "987"));
	uczelnia->dodajUzytkownika(new Wykladowca("login5", "haslo5", "654"));
	uczelnia->dodajUzytkownika(new Wykladowca("login6", "haslo6", "321"));


	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(0)->getLogin() << "\n";
	assert(uczelnia->logowanie("login1", "haslo1", true) == uczelnia->getUzytkownicy()->at(0));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(0)->wylogujSie();

	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(3)->getLogin() << "\n";
	assert(uczelnia->logowanie("login4", "haslo4", false) == uczelnia->getUzytkownicy()->at(3));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(3)->wylogujSie();

	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(5)->getLogin() << "\n";
	assert(uczelnia->logowanie("login6", "haslo6", false) == uczelnia->getUzytkownicy()->at(5));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(5)->wylogujSie();

	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(1)->getLogin() << "\n";
	assert(uczelnia->logowanie("login2", "haslo2", true) == uczelnia->getUzytkownicy()->at(1));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(1)->wylogujSie();

	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(4)->getLogin() << "\n";
	assert(uczelnia->logowanie("login5", "haslo5", false) == uczelnia->getUzytkownicy()->at(4));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(4)->wylogujSie();

	std::cout << "Logowanie uzytkownika o loginie: " << uczelnia->getUzytkownicy()->at(2)->getLogin() << "\n";
	assert(uczelnia->logowanie("login3", "haslo3", true) == uczelnia->getUzytkownicy()->at(2));
	std::cout << "OK\n\n";
	uczelnia->getUzytkownicy()->at(2)->wylogujSie();


	delete uczelnia;
}

int main() {
	std::cout << "Test: Logowanie\n\n";

	std::cout << "test():\n\n";
	test();

	return 0;
}