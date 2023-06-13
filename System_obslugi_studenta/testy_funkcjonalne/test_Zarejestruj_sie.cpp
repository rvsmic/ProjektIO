#include <iostream>
#include <cassert>
#include <sstream>

#include "../Narzedzie.h"
#include "../Przedmiot.h"
#include "../Student.h"
#include "../Uczelnia.h"
#include "../Uzytkownik.h"
#include "../Wykladowca.h"

void test(){
	Uczelnia* uczelnia = new Uczelnia("Nazwa");
	Uzytkownik* user;

	std::istringstream input("123\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login1", "haslo1", false);
	cout << ((Wykladowca*)user)->getIdentyfikator() << "\n";
	user->wylogujSie();
	cout << "\n\n";

	input.str("321\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login2", "haslo2", true);
	cout << ((Student*)user)->getNrAlbumu() << "\n";
	user->wylogujSie();
	cout << "\n\n";

	input.str("456\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login3", "haslo3", false);
	cout << ((Wykladowca*)user)->getIdentyfikator() << "\n";
	user->wylogujSie();
	cout << "\n\n";

	input.str("654\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login4", "haslo4", true);
	cout << ((Student*)user)->getNrAlbumu() << "\n";
	user->wylogujSie();
	cout << "\n\n";

	input.str("789\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login5", "haslo5", false);
	cout << ((Wykladowca*)user)->getIdentyfikator() << "\n";
	user->wylogujSie();
	cout << "\n\n";

	input.str("321\n");
	std::cin.rdbuf(input.rdbuf());
	user = uczelnia->rejestracja("login6", "haslo6", true);
	cout << ((Student*)user)->getNrAlbumu() << "\n";
	user->wylogujSie();
	cout << "\n\n";


	delete uczelnia;
}

int main() {
	std::cout << "Test: Zarejestruj sie\n\n";

	std::cout << "test():\n\n";
	test();

	return 0;
}