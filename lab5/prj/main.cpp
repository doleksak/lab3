#include "asc.hh"
#include <iostream>
#include <string>
#include "timer.hh"

using namespace std;

/*!
  \mainpage Tablica asocjacyjna

   Aplikacja jest przykładem implementacji tablicy asocjacyjnej.


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia: <BR>
   -dodanie lub usunięcie pary klucz,wartość z tablicy; <BR>
   -pobranie wartości podanego klucza; <BR>
   -zmiane wartości klucza; <BR>
   -pobranie liczby istniejących elementów; <BR>
   -sprawdzenie czy tablica nie jest pusta.  
*/


/*!
 * \file
 * \brief Funkcja main komunikuje sie z uzytkownikiem
 * i testuje program
 */

int main()
{
	Asc Tablica;
	timer t;
	int cz;
	string kl, spr, us, zm;
	int j, k;
	cout<<"Podaj liczbe elementow do dodania: "<<endl;
	cin>>j;

t.start();

for (int i = 1; i < j+1; i++)
{	
	cout<<"Podaj klucz: "<<endl;
	cin>>kl;
	Tablica.dodaj(i, kl);
}
	
t.stop();

cz = t.elapsed_us();

cout<<"Podaj klucz, a nastepnie wartosc ktora chcesz zmienic: "<<endl;
cin>>zm;
cin>>k;
Tablica.zastap(k,zm);
cout<<"Pobierz wartosc klucza: "<<endl;
cin>>spr;
cout<<"Podany klucz ma wartosc: "<<Tablica.pobierz(spr)<<endl<<endl;
cout<<"Podaj klucz do usuniecia: "<<endl;
cin>>us;
Tablica.usun(us);
cout<<"Liczba elementow: "<<Tablica.zlicz()<<endl;
cout<<"Czas: "<<cz<<" mikrosekund"<<endl;
}
