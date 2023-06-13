/*
    Testy integracyjne - top-down:
    
    - test_UzytkownicyUczelnia() - testuje dodawanie i usuwanie uzytkownikow w klasie Uczelnia
    - test_PrzedmiotyWykladowcyUczelnia() - testuje dodawanie i usuwanie przedmiotow wykladowcy w klasie Uczelnia
    
*/

#include <iostream>
#include <cassert>

#include "../Uczelnia.h"
#include "../Student.h"
#include "../Wykladowca.h"
#include "../Narzedzie.h"
#include "../Uzytkownik.h"
#include "../Przedmiot.h"

void test_UzytkownicyUczelnia(){
    std::cout << "\nTestuje uzytkownikow w klasie Uczelnia:\n\n";

    Uczelnia* uczelnia = new Uczelnia("Nazwa");
    Uzytkownik* uzytkownik_1 = new Student("login_1", "haslo_1", "123");
    Uzytkownik* uzytkownik_2 = new Student("login_2", "haslo_2", "456");
    Uzytkownik* uzytkownik_3 = new Wykladowca("login_3", "haslo_3", "789");

    uczelnia->dodajUzytkownika(uzytkownik_1);
    uczelnia->dodajUzytkownika(uzytkownik_2);
    uczelnia->dodajUzytkownika(uzytkownik_3);

    std::cout << "Ilosc uzytkownikow: " << uczelnia->getUzytkownicy()->size() << "\n";
    assert(uczelnia->getUzytkownicy()->size() == 3);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - czy jest studentem: " << uzytkownik_1->czyStudent << "\n";
    assert(uzytkownik_1->czyStudent == true);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 2 - czy jest studentem: " << uzytkownik_2->czyStudent << "\n";
    assert(uzytkownik_2->czyStudent == true);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 3 - czy jest studentem: " << uzytkownik_3->czyStudent << "\n";
    assert(uzytkownik_3->czyStudent == false);
    std::cout << "Ok\n\n";


    std::cout << "Usuwam uzytkownika 2\n";
    uczelnia->usunUzytkownika("login_2");
    std::cout << "Ilosc uzytkownikow: " << uczelnia->getUzytkownicy()->size() << "\n";
    assert(uczelnia->getUzytkownicy()->size() == 2);
    std::cout << "Ok\n\n";

    std::cout << "Znajdz studenta o numerze albumu '123':\n";
    assert(uczelnia->znajdzStudenta("123") == uzytkownik_1);
    std::cout << "Ok\n\n";

    std::cout << "Znajdz studenta o numerze albumu '456':\n";
    assert(uczelnia->znajdzStudenta("456") == nullptr);
    std::cout << "Ok\n\n";

    std::cout << "Znajdz studenta o numerze albumu '789':\n";
    assert(uczelnia->znajdzStudenta("789") == nullptr);
    std::cout << "Ok\n\n";


    std::cout << "Uzytkownik 1:\n\t - login: " << uzytkownik_1->getLogin() << "\n\t - haslo: " << uzytkownik_1->getHaslo() << "\n\t - numer albumu: " << ((Student*)uzytkownik_1)->getNrAlbumu() << "\n";
    assert(uzytkownik_1->getLogin() == "login_1" && uzytkownik_1->getHaslo() == "haslo_1" && ((Student*)uzytkownik_1)->getNrAlbumu() == "123");
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 3:\n\t - login: " << uzytkownik_3->getLogin() << "\n\t - haslo: " << uzytkownik_3->getHaslo() << "\n\t - numer albumu: " << ((Wykladowca*)uzytkownik_3)->getIdentyfikator() << "\n";
    assert(uzytkownik_3->getLogin() == "login_3" && uzytkownik_3->getHaslo() == "haslo_3" && ((Wykladowca*)uzytkownik_3)->getIdentyfikator() == "789");
    std::cout << "Ok\n\n";

    delete uczelnia;
}

void test_PrzedmiotyWykladowcyUczelnia(){
    std::cout << "\nTestuje przedmioty i wykladowcow w klasie Uczelnia:\n\n";

    Uczelnia* uczelnia = new Uczelnia("Nazwa");
    Uzytkownik* uzytkownik_1 = new Wykladowca("login_1", "haslo_1", "123");
    Uzytkownik* uzytkownik_2 = new Wykladowca("login_2", "haslo_2", "456");

    ((Wykladowca*)uzytkownik_1)->dodajPrzedmiot("Przedmiot 1");
    ((Wykladowca*)uzytkownik_1)->dodajPrzedmiot("Przedmiot 2");
    ((Wykladowca*)uzytkownik_2)->dodajPrzedmiot("Przedmiot 3");

    ((Wykladowca*)uzytkownik_1)->dodajMaterial(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0), "Material 1");
    ((Wykladowca*)uzytkownik_1)->dodajMaterial(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0), "Material 2");
    ((Wykladowca*)uzytkownik_1)->dodajMaterial(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(1), "Material 3");
    ((Wykladowca*)uzytkownik_2)->dodajMaterial(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0), "Material 4");

    uczelnia->dodajUzytkownika(uzytkownik_1);
    uczelnia->dodajUzytkownika(uzytkownik_2);

    std::cout << "Uzytkownik 1 - ilosc przedmiotow: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->size() == 2);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 2 - ilosc przedmiotow: " << ((Wykladowca*)uzytkownik_2)->getPrzedmioty()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->size() == 1);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - ilosc materialow w przedmiocie 1: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->size() == 2);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - ilosc materialow w przedmiocie 2: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(1)->getMaterialy()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(1)->getMaterialy()->size() == 1);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 2 - ilosc materialow w przedmiocie 1: " << ((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0)->getMaterialy()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0)->getMaterialy()->size() == 1);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - material 1 w przedmiocie 1: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->at(0) << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->at(0) == "Material 1");
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - material 2 w przedmiocie 1: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->at(1) << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0)->getMaterialy()->at(1) == "Material 2");
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 1 - material 1 w przedmiocie 2: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(1)->getMaterialy()->at(0) << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(1)->getMaterialy()->at(0) == "Material 3");
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 2 - material 1 w przedmiocie 3: " << ((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0)->getMaterialy()->at(0) << "\n";
    assert(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0)->getMaterialy()->at(0) == "Material 4");
    std::cout << "Ok\n\n";

    ((Wykladowca*)uzytkownik_1)->usunPrzedmiot(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->at(0));
    ((Wykladowca*)uzytkownik_2)->usunPrzedmiot(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->at(0));

    std::cout << "Uzytkownik 1 - ilosc przedmiotow: " << ((Wykladowca*)uzytkownik_1)->getPrzedmioty()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_1)->getPrzedmioty()->size() == 1);
    std::cout << "Ok\n\n";

    std::cout << "Uzytkownik 2 - ilosc przedmiotow: " << ((Wykladowca*)uzytkownik_2)->getPrzedmioty()->size() << "\n";
    assert(((Wykladowca*)uzytkownik_2)->getPrzedmioty()->size() == 0);
    std::cout << "Ok\n\n";

    delete uczelnia;
}

int main(){
    std::cout << "\nTesty integracyjne - top-down:\n\n";

    std::cout << "test_UzytkownicyUczelnia:\n";
    test_UzytkownicyUczelnia();
    std::cout << "\n\n\n";

    std::cout << "test_PrzedmiotyWykladowcyUczelnia:\n";
    test_PrzedmiotyWykladowcyUczelnia();

    return 0;
}