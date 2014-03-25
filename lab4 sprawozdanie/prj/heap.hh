#ifndef HEAP_HH
#define HEAP_HH
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class heap
 {
	public:

void heapify (int *tab, int heap_size, int i);
void budKopiec(int *tab, int ilosc_liczb);
void sort(int *tab, int ilosc_liczb);

};
#endif
