#ifndef MERGE_HH
#define MERGE_HH
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*!
 * \file
 * \brief Definiuje klase merges i jej metody
 */

class merges
 {
	public:
	

void merge(int *tablica, int start, int srodek, int koniec);
void merge_sort(int *tablica, int start, int koniec);

};
#endif