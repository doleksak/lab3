#include "graf.hh"
#include "timer.hh"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;



int main()
{
	Graf tab1, tab2, tab3;
	int V, V1, V2, l, Vend, cz;
	timer t;


tab2.dodaj_krawedz(1,2,3);
tab2.dodaj_krawedz(1,3,4);
tab2.dodaj_krawedz(1,7,3);

tab3.dodaj_krawedz(1,2,3);
tab3.dodaj_krawedz(1,3,4);
tab3.dodaj_krawedz(1,7,3);

tab1.add_node(1);
tab1.add_node(2);
tab1.add_node(3);
tab1.add_node(7);
tab1.add_edge(1,2,3);
tab1.add_edge(1,3,4);
tab1.add_edge(1,7,3);


t.start();
tab1.A_star(1,7);
t.stop();
cz = t.elapsed_us();
cout<<"Czas: "<<cz<<" mikrosekund"<<endl;


tab2.DFS(1,7);




//tab3.BFS(1,7);


}