#include "heap.hh"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*!
 * \file
 * \brief Metody klasy heap
 *
 */

/*! \brief Reorganizowanie elementow w celu
 *   utworzenia kopca
 */

void heap::heapify (int *tab, int heap_size, int i)
{
	int largest, temp;
	int l=2*i, r=(2*i)+1;
	if (l<=heap_size && tab[l]>tab[i])
		largest=l;
	else largest=i;
	if (r<=heap_size && tab[r]>tab[largest])
		largest=r;
	if (largest!=i)
	{
		temp=tab[largest];
		tab[largest]=tab[i];
		tab[i]=temp;
		heapify(tab,heap_size,largest);
	}
}

/*! \brief Wywoluje funkcje heapify w petli for
 *   
 */

void heap::budKopiec(int *tab, int ilosc_liczb)
{
	for (int i=ilosc_liczb/2;i>0;i--)
		heapify(tab,ilosc_liczb, i);
}

/*! \brief Wykonuje operacje sortowania poprzez kopcowanie
 *   
 */

void heap::sort(int *tab, int ilosc_liczb)
{
	int temp;
	budKopiec(tab, ilosc_liczb);
	for (int i=ilosc_liczb;i>1;i--)
	{
		temp=tab[i];
		tab[i]=tab[1];
		tab[1]=temp;
		ilosc_liczb--;
		heapify(tab,ilosc_liczb,1);
	}
}

