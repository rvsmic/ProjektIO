#include <cassert>
#include <iostream>
#include "../Narzedzie.h"

void testuj_nazwe(){
    Narzedzie narzedzie("nazwa", "link");
    std::cout << "\nTestuje nazwe narzedzia: ";
    assert(narzedzie.getNazwa() == "nazwa");
    std::cout << "Ok\n\n";
}

void testuj_link(){
    Narzedzie narzedzie("nazwa", "link");
    std::cout << "\nTestuje link narzedzia: ";
    assert(narzedzie.getLink() == "link");
    std::cout << "Ok\n\n";
}

int main(){
    testuj_nazwe();
    testuj_link();
    return 0;
}