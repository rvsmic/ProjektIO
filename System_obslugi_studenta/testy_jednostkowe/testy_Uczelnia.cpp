#include <cassert>
#include <iostream>
#include "../Uczelnia.h"

void testuj(){
    Uczelnia uczelnia("nazwa");
    std::cout << "\nTestuje nazwe uczelni: ";
    assert(uczelnia.getNazwa() == "nazwa");
    std::cout << "Ok\n\n";
}

int main(){
    testuj();

    return 0;
}