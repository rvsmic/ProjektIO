#include <cassert>
#include <iostream>
#include "../Wykladowca.h"

void testuj_dane_konta(){
    Wykladowca wykladowca("Login", "Haslo", "123456");
    std::cout << "\nTestuje dane konta: \n\n";

    std::cout << "> Czy student: " << wykladowca.czyStudent << "\n";
    assert(wykladowca.czyStudent == false);

    std::cout << "> Login: " << wykladowca.getLogin() << "\n";
    assert(wykladowca.getLogin() == "Login");

    std::cout << "> Haslo: " << wykladowca.getHaslo() << "\n";
    assert(wykladowca.getHaslo() == "Haslo");

    std::cout << "> Numer identyfikator: " << wykladowca.getIdentyfikator() << "\n";
    assert(wykladowca.getIdentyfikator() == "123456");

    std::cout << "Ok\n\n";
}

int main(){
    testuj_dane_konta();

    return 0;
}