#include "kolejka.hh"
#include <list>

using namespace std;

/*!
 * \file
 * \brief Definicje funkcji klasy kolejka
 *
 */

/*! \brief Zwraca rozmiar kolejki
 * 
 */

int kolejka::size()
		{
			return lista.size();
		}

/*! \brief Zwraca wartosc logiczna czy kolejka jest pusta
 * 
 */

bool kolejka::isEmpty()
	{
		return lista.empty();
	}

/*! \brief Dodaje element do kolejki
 * 
 */

void kolejka::enqueue ()
	{
		lista.push_back(1);
	}

/*! \brief Zdejmuje element z kolejki
 * 
 */

void kolejka::dequeue()
	{
		lista.pop_front();
	}

/*! \brief Wyswietla elementy kolejki
 * 
 */

void kolejka::wyswietl()
{  cout<<"Twoje elementy:"<<endl;
	for( list<int>::iterator iter=lista.begin(); iter != lista.end();){
		cout<<*iter<<endl;
         iter++;
	}
}