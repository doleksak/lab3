#include <iostream>
#include <cstdlib>
#include "quick.hh"
#include "timer.hh"
#include "heap.hh"
#include "merge.hh"
#include <ctime>
#include <fstream>


using namespace std;

/*!
  \mainpage Benchmark

   Aplikacja jest przykładem realizacji operacji sortowania


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia pomiar czasu wykonywanego sortowania dla zadanej liczby
  elementow i zapisanie danych do pliku csv. Realizowane operacje sortowania
  to: heapsort, mergesort, quicksort. Quicksort jest realizowany poprzez
  wybieranie skrajnego lub wylosowanego elementu do podzialu tablicy.

  
*/

/*! \file Funkcja main
 *
 * Funkcja wywoluje metody zawarte w programie
 */

int main()
{	

	ofstream str;
	timer t;
	quick test;
	heap test2;
	merges test3;
	int ilosc_liczb, i, j, cz;
	srand (time(NULL));

str.open("dane.csv");

	do
{   
	cout << "Podaj ilosc: ";
	cin >> ilosc_liczb;
	int *tablica = new int [ilosc_liczb]; 

int ros=ilosc_liczb;

	for (i = 0; i < ilosc_liczb; i++)
	{
		//tablica[i]=ros;
		//ros--;

		j=i;//rand() % 1000000;
		tablica[i]=j;
	}

t.start();
	
	test.quicksort(tablica,0,ilosc_liczb-1); 
	/*test2.sort(tablica,ilosc_liczb-1);*/
    /*test3.merge_sort(tablica, 0, ilosc_liczb-1);*/

t.stop();

cz = t.elapsed_us();

cout<<"Czas: "<<cz<<" mikrosekund"<<endl;

str<<cz<<endl;


	/*for (int c=0; c<ilosc_liczb; c++)
	{
		cout<<tablica[c] << " "<<endl;
	}*/

	

} while(ilosc_liczb!=13);

  
  str.close();

	return 0;

}

