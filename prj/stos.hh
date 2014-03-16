#ifndef STOS_HH
#define STOS_HH
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
using namespace std;

/*!
 * \file
 * \brief Definiuje klase stos i jej metody
 */

class stos
{
public:
	int *tab;
	int n;
	stos(): tab(0), n(0) {};
	~stos() {delete [] tab;};


	void dodaj_element();
	void usun_element();
	int ile();	
	void push();
	void pop();
	bool isEmpty();
	int size();
	void wyswietl();
	void podwoj();
	void pocwiart();
};

#endif