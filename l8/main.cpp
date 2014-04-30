#include "graf.hh"
#include "timer.hh"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
	Graf tab1;
	int V, l;


	cout<<"Podaj rozmiar grafu: "<<endl;
	cin>>l;

for (int i = 0; i < l; i++)
{	cout<<"Podaj wierzcholek: "<<endl;
	cin>>V;
	tab1.dodaj_wierzcholek(V);
}
tab1.dodaj_krawedz();
tab1.dodaj_krawedz();
tab1.dodaj_krawedz();
tab1.dodaj_krawedz();


int V1, V2;
cout<<"Podaj V1 czy sasiad: "<<endl;
	cin>>V1;
	cout<<"Podaj V2 czy sasiad: "<<endl;
	cin>>V2;
tab1.czy_sasiad(V1, V2);


cout<<"Podaj wierzcholek dla ktorego wyswietlic sasiedztwo: "<<endl;
	cin>>V;
tab1.sasiedztwo(V);




/*
cout<<"Podaj wierzcholek do usuniecia: "<<endl;
	cin>>V;
tab1.usun_wierzcholek(V);
*/


/*
cout<<"Podaj V1 do usuniecua krawedzi: "<<endl;
	cin>>V1;
	cout<<"Podaj V2 do usuniecua krawedzi: "<<endl;
	cin>>V2;
tab1.usun_krawedz(V1, V2);  */
tab1.wyswietl();

tab1.DFS(1);

}