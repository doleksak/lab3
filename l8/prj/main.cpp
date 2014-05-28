#include "graf.hh"
#include "timer.hh"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*!
  \mainpage Graf

   Aplikacja jest przykładem implementacji Grafu na liście sąsiadów, przeszukiwania wszerz, w głąb i algorytmu A*.


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia pomiar czasu wykonywanego algorytmu i wypisanie odwiedzonych wierzchołków
  przez jeden z algorytmów.
*/

/*! \file Funkcja main
 *
 * Funkcja wywoluje metody zawarte w programie
 */

int main()
{
	Graf tab1, tab2, tab3;
	int V, V1, V2, l, Vend, cz;
	timer t;


tab2.dodaj_krawedz(1,2,1);
tab2.dodaj_krawedz(1,8,2);
tab2.dodaj_krawedz(2,4,3);
tab2.dodaj_krawedz(2,6,4);

tab3.dodaj_krawedz(1,2,1);
tab3.dodaj_krawedz(1,8,2);
tab3.dodaj_krawedz(2,4,3);
tab3.dodaj_krawedz(2,6,4);

tab1.add_node(1);
tab1.add_node(2);
tab1.add_node(8);
tab1.add_node(4);
tab1.add_node(6);
tab1.add_edge(1,2,1);
tab1.add_edge(1,8,2);
tab1.add_edge(2,4,3);
tab1.add_edge(2,6,4);

t.start();
tab1.A_star(1,6);
t.stop();
cz = t.elapsed_us();
cout<<"Czas: "<<cz<<" mikrosekund"<<endl;


//tab2.DFS(1,6);




tab3.BFS(1,6);


}