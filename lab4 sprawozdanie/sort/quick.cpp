#include <iostream>
#include <cstdlib>
#include "quick.hh"
using namespace std;

/*!
 * \file
 * \brief Metody klasy quick
 *
 */

/*! \brief Dzieli tablice wedlug pivot. Element do podzialu
 *	jest elementem krancowym lub losowanym.
 * 
 */

int quick::partition(int *tablica, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
	srand (time(NULL));
	int pivot=p + rand() % (r-p);

	int x = tablica[pivot/*p*/]; // obieramy x 
	int i = p, j = r, w; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x 
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else // gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}

/*! \brief Metoda wywolujaca podzial tablic i rekurencyjne sortowanie quicksort
 * 
 */

void quick::quicksort(int *tablica, int p, int r) // sortowanie szybkie
{	
	
	int q;
	if (p < r) 
	{	
		q = partition(tablica,p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}
