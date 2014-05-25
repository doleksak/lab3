#include "graf.hh"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;




void Graf::wyswietl()
{
	for (int i = 0; i <50; i++)
	{
		cout << endl <<"  "<< " ";
		for (vector<int>::iterator it = lista_sasiedztwa[i].begin(); it != lista_sasiedztwa[i].end(); it++)
		{
			cout << " " << *it;
		}
	}
	cout << endl;
}


void Graf::czy_sasiad(int V1, int V2)
{
for (vector<int>::iterator it = lista_sasiedztwa[V1].begin(); it != lista_sasiedztwa[V1].end(); it++)
		{
			if (*it==V2)
			{
			cout << "Sasiaduja ze soba" <<endl;
			}			
		}
}

void Graf::sasiedztwo(int V)
{
	cout << "Sasiedztwo z: ";
for (vector<int>::iterator it = lista_sasiedztwa[V].begin(); it != lista_sasiedztwa[V].end(); it++)
		{
			
			cout<<*it<<" ";
			
		}
		cout<<endl;
}

void Graf::dodaj_wierzcholek(int V)
{ 
		lista_sasiedztwa[V].push_back(V);
}

void Graf::dodaj_krawedz(int V1, int V2, int waga)
{


Wierzcholek kraw;
kraw.waga = waga;
kraw.sasiad=V2;

lista_sasiadujaca[V1].push_back(kraw);
lista_sasiedztwa[V1].push_back(V2);

if (V1 != V2)
		{
			kraw.sasiad = V1;
			kraw.waga = waga;
			lista_sasiadujaca[V2].push_back(kraw);
			lista_sasiedztwa[V2].push_back(V1);
		}
				 
}

void Graf::usun_krawedz(int V1, int V2)
{
Wierzcholek kraw;
kraw.waga = 0;
kraw.sasiad=0;

lista_sasiadujaca[V1].push_back(kraw);
lista_sasiedztwa[V1].push_back(0);

if (V1 != V2)
		{
			kraw.sasiad = 0;
			kraw.waga = 0;
			lista_sasiadujaca[V2].push_back(kraw);
			lista_sasiedztwa[V2].push_back(0);
		}
}

void Graf::usun_wierzcholek(int V)
{
	for (int i = 0; i < V; i++)
	{
		lista_sasiedztwa[V].erase(lista_sasiedztwa[V].begin()+i);
	}
			
}

void ex (void)
	{
  cout<<" - sciezka przeszukiwania."<<endl;
	}


void Graf::Depth(int V, int Vend, bool visited[])
{	
    visited[V] = true;

    cout << V << " ";
    if(V==Vend)
    {               
  at_quick_exit (ex);
  quick_exit (EXIT_SUCCESS);
    }
    
    vector<int>::iterator i;
    for(i = lista_sasiedztwa[V].begin(); i != lista_sasiedztwa[V].end(); i++)
		if(!visited[*i])               
        Depth(*i, Vend, visited);       
        
        
    
}

void Graf::DFS(int V, int Vend)
{	
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    Depth(V, Vend, visited);
    cout<<endl;
}


void Graf::BFS(int V, int Vend)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    list<int> queue;
 
    visited[V] = true;
    queue.push_back(V);
 
    vector<int>::iterator i;
 
    while(!queue.empty())
    {        
        V = queue.front();
        cout << V << " ";

        if(V==Vend)
    {               
  at_quick_exit (ex);
  quick_exit (EXIT_SUCCESS);
    }

        queue.pop_front();
 
        for(i = lista_sasiedztwa[V].begin(); i != lista_sasiedztwa[V].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout<<endl;
}


Graf::~Graf()
{
	delete[] lista_sasiadujaca;
}


Graf::Graf(int wielkosc)
{
nodes = 0;
lista.resize(wielkosc,NULL);
}


void Graf::add_edge(int V1, int V2, int c)
{
if(this->lista[V1]!= NULL && this->lista[V2]!= NULL)
{
pathfind* wskaznik = this->lista[V1]->sasiedzi;
while(wskaznik->nast!=NULL)
{
if(wskaznik->neighbour == V2)
{
return;
}
wskaznik = wskaznik->nast;
}
wskaznik->nast = new pathfind;
wskaznik->neighbour = V2;
wskaznik->koszt = c;
}
else
cout<<"Blad"<<endl;
}

void Graf::add_node(int V)
{
int wielkosc_tablicy = this->lista.capacity();
if(V>wielkosc_tablicy)
{
vector<node*> nowy;
nowy.reserve(V*2);
for(int i = 1;i<V*2;++i)
{
if(i<wielkosc_tablicy)
nowy[i] = lista[i];
else
nowy[i] = NULL;
}
lista.swap(nowy);
}
if(this->lista[V]==NULL)
{
this->lista[V] = new node;
nodes += 1;
}
else
cout<<"Blad"<<endl;
}


int Graf::A_star(int V1, int V2)
{
list<int> closed_list;
list<int> open_list;
pathfind* wskaznik;
list<int>::iterator iter;
list<int>::iterator temporary;
int tmp;
bool tmp1, tmp2;
int suma_min = INT_MAX;
int vert;

if(this->lista[V1] != NULL && this->lista[V2] != NULL)
{
open_list.push_back(V1);
while(!open_list.empty())
{
for( iter=open_list.begin(); iter != open_list.end(); ++iter )
if(this->lista[*iter]->suma<suma_min)
{
vert = *iter;
temporary = iter;
cout<<vert<<endl;
}
open_list.erase(temporary);
closed_list.push_back(vert);
wskaznik = this->lista[vert]->sasiedzi;
if(vert==V2)
return 1;
while(wskaznik->nast!=NULL)
{
tmp1 = tmp2 = false;
for( iter=closed_list.begin(); iter != closed_list.end(); ++iter )
if(*iter==wskaznik->neighbour)
tmp1 = true;
for( iter=open_list.begin(); iter != open_list.end(); ++iter )
if(*iter==wskaznik->neighbour)
tmp2 = true;
if(tmp1) {}
else if(!tmp2)
{
open_list.push_back(wskaznik->neighbour);
this->lista[wskaznik->neighbour]->rodzic = vert;
this->lista[wskaznik->neighbour]->distance = wskaznik->koszt;
this->lista[wskaznik->neighbour]->szac = (this->lista[wskaznik->neighbour]->szac+wskaznik->koszt)/1.5;
this->lista[wskaznik->neighbour]->suma = this->lista[wskaznik->neighbour]->szac+
this->lista[wskaznik->neighbour]->distance;
}
else
{
tmp = this->lista[wskaznik->neighbour]->distance + wskaznik->koszt;
if(tmp<this->lista[wskaznik->neighbour]->distance)
{
this->lista[wskaznik->neighbour]->rodzic = vert;
this->lista[wskaznik->neighbour]->distance = tmp;
this->lista[wskaznik->neighbour]->suma = this->lista[wskaznik->neighbour]->szac+
this->lista[wskaznik->neighbour]->distance;
}
}
wskaznik = wskaznik->nast;
}
}
}
else
cout<<"Blad"<<endl;
return 0;
}