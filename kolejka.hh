#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
using namespace std;

class kolejka
{
public:
	list<int> lista;
	int size();
	bool isEmpty();
	void enqueue ();	
	void dequeue ();
	void wyswietl();

};







#endif