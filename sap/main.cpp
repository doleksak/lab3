#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include "sap.hh"


using namespace std;

int main()
    {

saper a;
int o;
do
{    
cout<<"----------------------------------------------------------------"<<endl;
cout<<"  ___               ___ ___  ___ ___  ___ ___			"<<endl;
cout<<" |o o|             |ooo|ooo||ooo|o o||o o|o o|			"<<endl;
cout<<" |o_o| ___ ___  ___|ooo|ooo||ooo|o_o||o_o|_o_|___		"<<endl;
cout<<" |o  ||o  |o  ||o  |ooo|                 |o o|o  |		"<<endl;
cout<<" |__o||__o|__o||__o|ooo|                 |_o_|__o|		"<<endl;
cout<<"															"<<endl;
cout<<"															"<<endl;
cout<<"															"<<endl;
cout<<"															"<<endl;
cout<<"	1)----------------- Bede gral w gre --------------------"<<endl;
cout<<"	2)-------------------- Zasady gry ----------------------"<<endl;
cout<<"	3)--------------------- Wyjscie ------------------------"<<endl;
cout<<"----------------------------------------------------------------"<<endl<<endl;
cout<<"Mój wybór: "<<endl;

cin>>o;

if (o==1)
{
	a.graj();
}
if (o==2)
{
	a.instr();
}

}while(o!=3);


    	return 0;
    }