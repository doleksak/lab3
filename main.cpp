#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stos.hh"
#include <stack>
#include <ctime>
using namespace std;

int main() 
{
	int powtorz=0;  /*liczba powtorzen operacji*/
	clock_t t1, t2; /*stale czasu*/
	double czas; 	/*zmierzony czas wykonywania operacji*/
cout<<"podaj liczbe powtorzen"<<endl;
cin>>powtorz;

stos test;

t1=clock();
for (int i = 0; i < powtorz; i++)
{

  test.podwoj();

}
/*test.wyswietl();*/
t2=clock();
czas=t2-t1; 
double t=czas/CLOCKS_PER_SEC;
cout<<"czas:"<<t<<endl;    /*podanie czasu na wyjsciu*/

 ofstream str;
  str.open("dane.csv");
  str << "Czas: " << t << endl;  
  str.close();

return 0;

}