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

	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->dodajPrzedmiot("p_1");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(0)->dodajMaterial("Material 1");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(0)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(0)->getMaterialy()->at(0) == "Material 1");
	std::cout << "Ok\n\n";

	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->dodajPrzedmiot("p_2");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(1)->dodajMaterial("Material 2");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(1)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(1)->getMaterialy()->at(0) == "Material 2");
	std::cout << "Ok\n\n";

	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->dodajPrzedmiot("p_3");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(2)->dodajMaterial("Material 3");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(2)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(0))->getPrzedmioty()->at(2)->getMaterialy()->at(0) == "Material 3");
	std::cout << "Ok\n\n";

	
	uczelnia->dodajUzytkownika(new Wykladowca("login2", "haslo2", "456"));

	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->dodajPrzedmiot("p_4");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(0)->dodajMaterial("Material 4");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(0)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(0)->getMaterialy()->at(0) == "Material 4");
	std::cout << "Ok\n\n";

	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->dodajPrzedmiot("p_5");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->dodajMaterial("Material 5");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->getMaterialy()->at(0) == "Material 5");
	std::cout << "Ok\n\n";

	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->dodajMaterial("Material 6");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->getMaterialy()->at(1) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(1)->getMaterialy()->at(1) == "Material 6");
	std::cout << "Ok\n\n";

	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->dodajPrzedmiot("p_6");
	((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(2)->dodajMaterial("Material 7");
	std::cout << "Utworzony material: " << ((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(2)->getMaterialy()->at(0) << "\n";
	assert(((Wykladowca*)uczelnia->getUzytkownicy()->at(1))->getPrzedmioty()->at(2)->getMaterialy()->at(0) == "Material 7");
	std::cout << "Ok\n\n";

	delete uczelnia;
}

int main() {
	std::cout << "Test: Dodaj materialy z przedmiotow\n\n";

	std::cout << "test():\n\n";
	test();

	return 0;
}