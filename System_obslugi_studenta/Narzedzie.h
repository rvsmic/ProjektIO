//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Narzedzie.h
//  @ Date : 24.05.2023
//  @ Author : 
//
//


#if !defined(_NARZEDZIE_H)
#define _NARZEDZIE_H

#include <iostream>
#include <string>

using namespace std;

class Narzedzie {
public:
	Narzedzie(string nazwa, string link);
	void setNazwa(string nazwa);
	string getNazwa();
	void setLink(string link);
	string getLink();
	void uruchomNarzedzie();
private:
	string nazwa;
	string link;
};

#endif  //_NARZEDZIE_H
