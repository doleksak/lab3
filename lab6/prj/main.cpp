#include "asc.hh"
#include "drzewo.hh"
#include "timer.hh"
#include "hasz.hh"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
srand (time(NULL));
Asc Tablica;
int j, cz;
timer t;
drzewo d;

hasztab ht;
string st;


cout<<"Podaj liczbe elementow: "<<endl;
cin>>j;


/* hash
for (int i = 0; i < j-1; i++)
{ 
st = "klucz";
  ht.add(st, i);
}
  ht.add("koniec", j);

t.start();
ht.find("koniec");
t.stop();
*/




/* drzewo
for (int i = 0; i < j; i++)
{
  d.insert(i);
}

t.start();
d.search(j-3);
t.stop();
*/



 
for (int i = 0; i < j-1; i++)
{ 
string a = "klucz";
  Tablica.dodaj(i, a);
}
Tablica.dodaj(j+1, "koniec");

t.start();
Tablica.pobierz("koniec");
t.stop();





cz = t.elapsed_us();
cout<<"Czas: "<<cz<<" mikrosekund"<<endl;

return 0;
}