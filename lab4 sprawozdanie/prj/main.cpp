#include <iostream>
#include <cstdlib>
#include "quick.hh"
#include "timer.hh"
#include "heap.hh"
#include "merge.hh"
#include <ctime>

using namespace std;


int main()
{
	timer t;
	quick test;
	heap test2;
	merges test3;
	int ilosc_liczb, i, j;
	srand (time(NULL));
	do
{   
	cout << "Podaj ilosc: ";
	cin >> ilosc_liczb;
	int *tablica = new int [ilosc_liczb]; 

	for (i = 0; i < ilosc_liczb; i++)
	{
		j=rand() % 1000000;
		tablica[i]=j;
	}
t.start();

	
	test.quicksort(tablica,0,ilosc_liczb-1); 
	/*test2.sort(tablica,ilosc_liczb-1);*/
    /*test3.merge_sort(tablica, 0, ilosc_liczb-1);*/

t.stop();
t.wyswietl();

	/*for (int c=0; c<ilosc_liczb; c++)
	{
		cout<<tablica[c] << " "<<endl;
	}*/

	

} while(ilosc_liczb!=0);

	

	return 0;

}
