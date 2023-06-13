/*
    Testy integracyjne - bottom-up:
    
    - test_NarzedzieUczelnia() - testuje dodawanie i usuwanie narzedzi w klasie Uczelnia
    - test_PrzedmiotWykladowca() - testuje dodawanie i usuwanie przedmiotow w klasie Wykladowca
    - test_WykladowcaPrzedmiot() - testuje wykladowce w klasie Przedmiot
    
*/

#include <iostream>
#include <cassert>

#include "../Uczelnia.h"
#include "../Student.h"
#include "../Wykladowca.h"
#include "../Narzedzie.h"
#include "../Uzytkownik.h"
#include "../Przedmiot.h"

void test_NarzedzieUczelnia(){
    std::cout << "\nTestuje narzedzia w klasie Uczelnia:\n\n";

    Uczelnia* uczelnia = new Uczelnia("Nazwa");
    Narzedzie narzedzie_1("n1", "l1");
    Narzedzie narzedzie_2("n2", "l2");
    Narzedzie narzedzie_3("n3", "l3");

    uczelnia->dodajNarzedzie(&narzedzie_1);
    uczelnia->dodajNarzedzie(&narzedzie_2);

    uczelnia->wyswietlNarzedzia();
    std::cout << "\t---\n";

    uczelnia->usunNarzedzie("n1");
    uczelnia->usunNarzedzie("n2");
    uczelnia->dodajNarzedzie(&narzedzie_3);

    uczelnia->wyswietlNarzedzia();
    std::cout << "\t---\n";

    uczelnia->usunNarzedzie("n3");

    uczelnia->wyswietlNarzedzia();
    std::cout << "\t---\n";

    delete uczelnia;
}

void test_PrzedmiotWykladowca(){
    std::cout << "\nTestuje przedmioty w klasie Wykladowca:\n\n";

    Wykladowca* wykladowca = new Wykladowca("login", "haslo", "123456");
    
    wykladowca->dodajPrzedmiot("p1");
    wykladowca->dodajPrzedmiot("p2");

    std::cout << "Ilosc przedmiotow: " << wykladowca->getPrzedmioty()->size() << "\n";
    assert(wykladowca->getPrzedmioty()->size() == 2);
    std::cout << "Ok\n\n";
    
    std::cout << "Przedmiot 1: " << wykladowca->getPrzedmioty()->at(0)->getNazwa() << "\n";
    assert(wykladowca->getPrzedmioty()->at(0)->getNazwa() == "p1");
    std::cout << "Ok\n\n";
    
    std::cout << "Przedmiot 2: " << wykladowca->getPrzedmioty()->at(1)->getNazwa() << "\n";
    assert(wykladowca->getPrzedmioty()->at(1)->getNazwa() == "p2");
    std::cout << "Ok\n\n";


    wykladowca->usunPrzedmiot(wykladowca->getPrzedmioty()->at(0));

    std::cout << "Ilosc przedmiotow: " << wykladowca->getPrzedmioty()->size() << "\n";
    assert(wykladowca->getPrzedmioty()->size() == 1);
    std::cout << "Ok\n\n";

    std::cout << "Przedmiot 1: " << wykladowca->getPrzedmioty()->at(0)->getNazwa() << "\n";
    assert(wykladowca->getPrzedmioty()->at(0)->getNazwa() == "p2");
    std::cout << "Ok\n\n";

    wykladowca->dodajPrzedmiot("p3");

    std::cout << "Ilosc przedmiotow: " << wykladowca->getPrzedmioty()->size() << "\n";
    assert(wykladowca->getPrzedmioty()->size() == 2);
    std::cout << "Ok\n\n";

    std::cout << "Przedmiot 1: " << wykladowca->getPrzedmioty()->at(0)->getNazwa() << "\n";
    assert(wykladowca->getPrzedmioty()->at(0)->getNazwa() == "p2");
    std::cout << "Ok\n\n";

    std::cout << "Przedmiot 2: " << wykladowca->getPrzedmioty()->at(1)->getNazwa() << "\n";
    assert(wykladowca->getPrzedmioty()->at(1)->getNazwa() == "p3");
    std::cout << "Ok\n\n";


    delete wykladowca;
}

void test_WykladowcaPrzedmiot(){
    std::cout << "\nTestuje wykladowce w klasie Przedmiot:\n\n";

    Wykladowca* wykladowca = new Wykladowca("login", "haslo", "123456");
    Przedmiot* przedmiot = new Przedmiot("nazwa", wykladowca);

    std::cout << "Wykladowca - login: " << przedmiot->getWykladowca()->getLogin() << "\n";
    assert(przedmiot->getWykladowca()->getLogin() == "login");
    std::cout << "Ok\n\n";

    std::cout << "Wykladowca - haslo: " << przedmiot->getWykladowca()->getHaslo() << "\n";
    assert(przedmiot->getWykladowca()->getHaslo() == "haslo");
    std::cout << "Ok\n\n";

    std::cout << "Wykladowca - identyfikator: " << przedmiot->getWykladowca()->getIdentyfikator() << "\n";
    assert(przedmiot->getWykladowca()->getIdentyfikator() == "123456");
    std::cout << "Ok\n\n";

    delete przedmiot;
    delete wykladowca;
}

int main(){
    std::cout << "\nTesty integracyjne - bottom-up:\n\n";

    std::cout << "test_NarzedzieUczelnia:\n";
    test_NarzedzieUczelnia();
    std::cout << "\n\n\n";

    std::cout << "test_PrzedmiotWykladowca:\n";
    test_PrzedmiotWykladowca();
    std::cout << "\n\n\n";
    
    std::cout << "test_WykladowcaPrzedmiot:\n";
    test_WykladowcaPrzedmiot();

    return 0;
}