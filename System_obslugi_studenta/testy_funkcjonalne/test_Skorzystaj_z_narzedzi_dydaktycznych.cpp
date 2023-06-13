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

	Narzedzie* word = new Narzedzie("Word", "www.word.com");
	Narzedzie* excel = new Narzedzie("Excel", "www.excel.com");
	Narzedzie* powerpoint = new Narzedzie("PowerPoint", "www.powerpoint.com");

	uczelnia->dodajNarzedzie(word);
	uczelnia->dodajNarzedzie(excel);
	uczelnia->dodajNarzedzie(powerpoint);

	uczelnia->dodajUzytkownika(new Student("login1", "haslo1", "123"));
	uczelnia->dodajUzytkownika(new Wykladowca("login2", "haslo2", "456"));
	

	Uzytkownik* uzytkownik = uczelnia->logowanie("login1", "haslo1", true);
	uczelnia->wyswietlNarzedzia();
	uczelnia->skorzystajZNarzedzia("Word");
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login2", "haslo2", false);
	uczelnia->wyswietlNarzedzia();
	uczelnia->skorzystajZNarzedzia("Excel");
	uzytkownik->wylogujSie();

	uzytkownik = uczelnia->logowanie("login1", "haslo1", true);
	uczelnia->wyswietlNarzedzia();
	uczelnia->skorzystajZNarzedzia("PowerPoint");
	uzytkownik->wylogujSie();


	delete uczelnia;
}

int main() {
	cout << "Test: Skorzystaj z narzedzi dydaktycznych\n\n";

	cout << "test():\n\n";

	test();

	return 0;
}