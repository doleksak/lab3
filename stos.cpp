#include "stos.hh"
using namespace std;

 void stos::push()
{	
		
		stos::dodaj_element();

}

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
		tab[n]=1;
		n++;
	}
}

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


void stos::pop()
{
	stos::usun_element();
}


int stos::ile()
	{
		return n;
	}

bool stos::isEmpty()
	{
		return (stos::ile()==0);
	}


int  stos::size()
	{
		return stos::ile();
	}


void stos::wyswietl() 
	{
	for(int i=0; i<n; i++) { cout<<tab[i]<<" "; }
	cout<<endl;
	}