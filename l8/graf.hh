#ifndef GRAF_HH
#define GRAF_HH
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

 using namespace std;


class Krawedz
{
public:
    int poczatek;
    int koniec;
    int w; /*waga*/
};

class Wierzcholek  
{
public:
    int sasiad;
    int waga;
    Wierzcholek(){ sasiad = 0; waga = 0; };
};

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
void dodaj_krawedz();
void usun_krawedz(int V1, int V2);
void usun_wierzcholek(int V);
void wyswietl(); 
void DFSUnreach(int v, int Vend, bool visited[]);
void DFS(int V, int Vend);
void BFS(int V, int Vend);

Graf(){lista_sasiadujaca = new vector<Wierzcholek>[50]; lista_sasiedztwa = new vector<int>[50];}
~Graf();
};

#endif