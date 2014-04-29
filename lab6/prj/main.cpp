#include "asc.hh"
#include "drzewo.hh"
#include "timer.hh"
#include "hasz.hh"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*!
  \mainpage Struktury

   Aplikacja jest przykładem implementacji struktur drzewa poszukiwań binarnych, tablicy asocjacyjnej i mieszającej.


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia pomiar czasu pobrania klucza dla zadanej liczby
  elementow. Operacje wykonywane są na:
  drzewie poszukiwań binarnych, tablicy asocjacyjnej, tablicy mieszającej.

  
*/

/*! \file Funkcja main
 *
 * Funkcja wywoluje metody zawarte w programie
 */

int main()
{
srand (time(NULL));
Asc Tablica;
int j, cz, k;
timer t;
drzewo d;

hasztab ht;
string st;


cout<<"Podaj liczbe elementow: "<<endl;
cin>>j;


/* hash */
st = "klucz";

for (int i = 0; i < j-1; i++)
{ 
  ht.add(st+="a", i);
}
  ht.add("kluczb", j);
  
t.start();
ht.find("kluczb");
t.stop();




/* drzewo 
int h;
for (int i = 1; i < j; i++)
{
  d.insert(i);
}
d.insert(j);
t.start();
k=d.search(j);
t.stop();
cout<<k<<endl;

*/

 /*
for (int i = 0; i < j-1; i++)
{ 
string a = "klucz";
  Tablica.dodaj(i, a+="a");
}
Tablica.dodaj(j, "koniec");

t.start();
Tablica.pobierz("koniec");
t.stop();
*/




cz = t.elapsed_us();
cout<<"Czas: "<<cz<<" mikrosekund"<<endl;

return 0;
}