#ifndef QUICK_HH
#define QUICK_HH
#include <iostream>

using namespace std;

/*!
 * \file
 * \brief Definiuje klase quick i jej metody
 */

class quick 
{
	public:
	int partition(int *tablica, int m, int n);
	void quicksort(int *tablica, int m, int n);

};
#endif
