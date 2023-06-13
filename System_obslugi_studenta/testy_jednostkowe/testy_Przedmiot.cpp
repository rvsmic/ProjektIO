#include <cassert>
#include <iostream>
#include "../Przedmiot.h"

void testuj_nazwe(){
    Przedmiot przedmiot("nazwa", nullptr);
    std::cout << "\nTestuje nazwe przedmiotu: ";
    assert(przedmiot.getNazwa() == "nazwa");
    std::cout << "Ok\n\n";
}

void testuj_materialy(){
    Przedmiot przedmiot("nazwa", nullptr);
    
    std::cout << "\nTestuje materialy przedmiotu: \n\n";
    przedmiot.dodajMaterial("link1");
    przedmiot.dodajMaterial("link2");
    przedmiot.dodajMaterial("link3");

    std::vector<std::string>* materialy = przedmiot.getMaterialy();
    assert(materialy->size() == 3);
    std::cout << "> Rozmiar: " << materialy->size() << "\n";
    assert((*materialy)[0] == "link1");
    std::cout << "> Link 1: " << (*materialy)[0] << "\n";
    assert((*materialy)[1] == "link2");
    std::cout << "> Link 2: " << (*materialy)[1] << "\n";
    assert((*materialy)[2] == "link3");
    std::cout << "> Link 3: " << (*materialy)[2] << "\n";
    std::cout << "Ok\n\n";

}

int main(){
    testuj_nazwe();
    testuj_materialy();
    return 0;
}