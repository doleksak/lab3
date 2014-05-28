#ifndef GRAF_HH
#define GRAF_HH
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <climits>
#include <list>

 using namespace std;

/*!
 * \file
 * \brief Definiuje klasy Krawedz, Wierzcholek oraz Graf i ich metody
 */

/*! \brief Klasa Krawedz
 * 
 */
class Krawedz
{
public:
    int poczatek;
    int koniec;
    int w;
};
/*! \brief Klasa Wierzcholek
 * 
 */
class Wierzcholek  
{
public:
    int sasiad;
    int waga;
    Wierzcholek(){ sasiad = 0; waga = 0; };
};
/*! \brief Klasa Graf wykorzystywana w programie
 * 
 */
class Graf
{
public:
    int V; 
    int E;
    vector<Wierzcholek> *lista_sasiadujaca;
    vector<int> *lista_sasiedztwa;    

void czy_sasiad(int V1, int V2);
void sasiedztwo(int V);
void dodaj_wierzcholek(int V);
void dodaj_krawedz(int V1, int V2, int waga);
void usun_krawedz(int V1, int V2);
void usun_wierzcholek(int V);
void wyswietl(); 
void Depth(int v, int Vend, bool visited[]);
void DFS(int V, int Vend);
void BFS(int V, int Vend);
void add_node(int V);
void add_edge(int V1, int V2, int c);
int A_star(int V1, int V2);

Graf(){lista_sasiadujaca = new vector<Wierzcholek>[50]; lista_sasiedztwa = new vector<int>[50]; nodes = 0;
lista.resize(10,NULL);}
Graf(int wielkosc);
~Graf();
/*! \brief Struktura należąca do klasy Graf, pozwalająca na realizację algorytmu A*
 * 
 */
struct pathfind
{
pathfind* nast;
int neighbour;
int koszt;
pathfind()
{neighbour = 0;koszt = 0;nast = NULL;}
};
/*! \brief Struktura należąca do klasy Graf, pozwalająca na realizację algorytmu A*, poprzez zmianę stałych, które pełnią rolę funkcji heurystycznej
 * 
 */
struct node
{
pathfind* sasiedzi;
float distance;
float szac;
int rodzic;
float suma;
node()
{suma = 0;szac = 5;distance = 10;rodzic = 0;sasiedzi = new pathfind;}
};
    vector<node*> lista;
    int nodes;   
};

#endif