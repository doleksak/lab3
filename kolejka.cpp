#include "kolejka.hh"
#include <list>

using namespace std;

int kolejka::size()
		{
			return lista.size();
		}

bool kolejka::isEmpty()
	{
		return lista.empty();
	}

void kolejka::enqueue ()
	{
		lista.push_back(1);
	}

void kolejka::dequeue()
	{
		lista.pop_front();
	}

void kolejka::wyswietl()
{  cout<<"Twoje elementy:"<<endl;
	for( list<int>::iterator iter=lista.begin(); iter != lista.end();){
		cout<<*iter<<endl;
         iter++;
	}
}