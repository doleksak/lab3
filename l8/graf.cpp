#include "graf.hh"
#include <iostream>
#include <vector>

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

void Graf::dodaj_krawedz()
{
int V1, V2, waga;

cout<<"Podaj V1: "<<endl;
	cin>>V1;
	cout<<"Podaj V2: "<<endl;
	cin>>V2;
	cout<<"Podaj wage: "<<endl;
	cin>>waga;


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

void Graf::usun_krawedz(int V1, int V2) /* tymczasowo */
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

void Graf::DFSUnreach(int V, bool visited[])
{
    visited[V] = true;
    cout << V << " ";
    vector<int>::iterator i;
    for(i = lista_sasiedztwa[V].begin(); i != lista_sasiedztwa[V].end(); i++)
        if(!visited[*i])
            DFSUnreach(*i, visited);
}

void Graf::DFS(int V)
{	
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    DFSUnreach(V, visited);
    cout<<endl;
}

Graf::~Graf()
{
	delete[] lista_sasiadujaca;
}