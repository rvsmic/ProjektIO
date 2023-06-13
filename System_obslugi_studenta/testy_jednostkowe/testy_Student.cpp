#include <cassert>
#include <iostream>
#include "../Student.h"

void testuj_dane_konta(){
    Student student("Login", "Haslo", "123456");
    std::cout << "\nTestuje dane konta: \n\n";

    std::cout << "> Czy student: " << student.czyStudent << "\n";
    assert(student.czyStudent == true);

    std::cout << "> Login: " << student.getLogin() << "\n";
    assert(student.getLogin() == "Login");

    std::cout << "> Haslo: " << student.getHaslo() << "\n";
    assert(student.getHaslo() == "Haslo");

    std::cout << "> Numer albumu: " << student.getNrAlbumu() << "\n";
    assert(student.getNrAlbumu() == "123456");

    std::cout << "Ok\n\n";
}

int main(){
    testuj_dane_konta();

    return 0;
}