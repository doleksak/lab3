#include "stos.hh"
using namespace std;

/*!
 * \file
 * \brief Metody klasy stos
 *
 */

/*! \brief Dodaje element na stos
 * 
 */

 void stos::push()
{	
		
		stos::dodaj_element();

}

/*! \brief Wykonuje operacje powiekszenia tablicy o 1
 * 
 */


void stos::dodaj_element()
{
	int *T = new int [n]; 	
	for(int i=0; i<n; i++)
      T[i]=tab[i];  			
		tab = new int[n+1]; 		
	for(int i=0; i<n; i++)
        tab[i]=T[i];  			
	tab[n]=1; 					
	delete [] T; 					
	n++;
}

/*! \brief Wykonuje operacje podwojenia tablicy, gdy
 *	liczba jej elementow ma przekroczyc rozmiar.
 * 
 */

void stos::podwoj()
{ int m=n;
	if ((m+1)>stos::ile())
	{
		tab = new int[2*n];
		tab[n+1]=1;
		n++;
	}
	else 
	{
		tab[n+1]=1;
		n++;
	}
}

/*! \brief Wykonuje operacje zmniejszenia tablicy, gdy
 *	liczba jej elementow stanowi 1/4 rozmiaru.
 * 
 */

void stos::pocwiart()
{ int m=n;
	if ((m-1)<stos::ile()/4)
	{
		tab = new int[1/4*n];
		n--;
	}
	else 
	{
		n--;
	}
}

/*! \brief Wykonuje operacje zmniejszenia tablicy o 1.
 * 
 */

void stos::usun_element() 
	{
	int *T = new int [n-1]; 		
	for(int i=0; i<n; i++)
        T[i]=tab[i];  			
		tab = new int[n-1]; 		
	for(int i=0; i<n; i++)
        tab[i]=T[i];  			 					
	delete [] T; 					
	n--;
	}

/*! \brief Usuwa element.
 * 
 */

void stos::pop()
{
	stos::usun_element();
}

/*! \brief Zwraca rozmiar tablicy.
 * 
 */

int stos::ile()
	{
		return n;
	}

/*! \brief Zwraca wartosc logiczna czy stos jest pusty.
 * 
 */

bool stos::isEmpty()
	{
		return (stos::ile()==0);
	}

/*! \brief Zwraca rozmiar stosu.
 * 
 */

int  stos::size()
	{
		return stos::ile();
	}

/*! \brief Wyswietla stos.
 * 
 */

void stos::wyswietl() 
	{
	for(int i=0; i<n; i++) { cout<<tab[i]<<" "; }
	cout<<endl;
	}