#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stos.hh"
#include "kolejka.hh"
#include <stack>
#include <ctime>
using namespace std;

/*!
  \mainpage Benchmark

   Aplikacja jest przykładem realizacji działań na tablicach i listach


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia pomiar czasu wykonywanej operacji dla zadanej liczby
  powtorzen i zapisanie danych do pliku csv.

  
*/

/*! \file Funkcja main
 *
 * Funkcja wywoluje metody zawarte w programie
 */

int main() 
{
	int powtorz=0;  /*liczba powtorzen operacji*/
	clock_t t1, t2; /*stale czasu*/
	double czas; 	/*zmierzony czas wykonywania operacji*/
cout<<"podaj liczbe powtorzen"<<endl;
cin>>powtorz;

stos test;
kolejka test2;

t1=clock();
for (int i = 0; i < powtorz; i++)
{  /*test.podwoj();*/

test2.enqueue();

}
/*test.wyswietl();*/
/*test2.wyswietl();*/
t2=clock();
czas=t2-t1; 
double t=czas/CLOCKS_PER_SEC;
cout<<"czas:"<<t<<endl;    /*podanie czasu na wyjsciu*/

 ofstream str;
  str.open("dane.csv");
  str << "Czas: " << t << endl;  
  str.close();

return 0;

}