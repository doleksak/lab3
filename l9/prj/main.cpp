#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include "sim.hh"


using namespace std;

/*!
  \mainpage Simplex

   Aplikacja jest przykładem implementacji algorytmu Simplex do rozwiązywania zadań programowania liniowego .


  \section etykieta-wazne-cechy Najważniejsze cechy

  Program umozliwia znalezienie maksimum dla zdefiniowanej funkcji celu.
  
*/

/*! \file Funkcja main
 *
 * Funkcja wywoluje metody zawarte w programie
 */

int IC, IV;      
double *DATA;
double delta=0.0001;
double maxc[100];
sim a;


void loadData()
{
     int i,j;	  
	 maxc[0]=0;
     ifstream plik;
     plik.open("Input.txt");
     plik>>IV;
     plik>>IC;
	 DATA = new double  [(IV+1)*(IC+1)];
	 cout<<"Tabela Simplex:"<<endl;
	 cout<<"----------------------------------"<<endl;
     for(i=0;i<IC+1;i++){
		 for(j=0;j<IV+1;j++){
		 plik>>DATA[i*(IV+1)+j];
		 
		 cout<<DATA[i*(IV+1)+j]<<" ";  
		 }
		 cout<<endl;
	 }
	 cout<<"----------------------------------"<<endl;
}



void dodajOgraniczenie(double *tab,double *tabo, char rodzaj,double miejsce, int wartosc,int NV,int NC,int NCM)
{
   
	 for(int i=0;i<NC;i++)
	 {
		 for(int j=0;j<NV+1;j++)
		 {
		    tabo[i*(NV+1)+j]=tab[i*(NV+1)+j];
		 }
	 }
	if(NCM==0){
	 for(int w=0;w<NV;w++)
	 {
		 if(w==miejsce){
			tabo[(NV+1)*NC+w]=1;		
		 }
		 else{
			 tabo[(NV+1)*NC+w]=0;
		 }
	 }
	 tabo[(NC+1)*(NV+1)-1]=wartosc;
   }
   else{
	  for(int w=0;w<NV;w++)
	  {
		 if(w==miejsce){
			tabo[(NV+1)*NC+w]=1;
		 }
		 else{
			 tabo[(NV+1)*NC+w]=0;
		 }
	  }
	 tabo[(NC+1)*(NV+1)-1]=wartosc;
	  if(rodzaj=='<'){
		  double tempor;
		for(int w=0;w<NV+1;w++){
			tempor=tabo[(NV+1)*NC+w];
			tabo[(NV+1)*NC+w]=tabo[(NV+1)*(NC-NCM)+w];
			tabo[(NV+1)*(NC-NCM)+w]=tempor;
		 }
	  }
	  }
}



void brb(double *tab,int NV,int nc, int ncm)
{
	double *wyniki=new double[100];
	double temp=-1,tempx=-999;
	int tx;
	int NC=nc+ncm;

	double *tab1,*tab2;
	tab1 = new double  [(NC+2)*(NV+1)];
	tab2 = new double  [(NC+2)*(NV+1)];

	

	a.simplex(tab,&wyniki[0],NV,nc,ncm);

	for(int i=0;i<NV+1;i++)
	{
		if(wyniki[i]<0)
			wyniki[i]=0;
	}

	if(wyniki[0]>0){
	
			if(tempx>0)
			{
				tx=int(tempx);
				dodajOgraniczenie(tab,tab1,'<', temp , tx , NV , NC+1,ncm);
		
				brb(tab1,NV,nc+1,ncm);

				dodajOgraniczenie(tab,tab2,'>', temp , tx+1 , NV , NC+1,ncm);
								
				brb(tab2,NV,nc,ncm+1);				
				}
			else{
					if(maxc[0]<wyniki[0])
					{
						for(int i=0;i<NV+1;i++)
							maxc[i]=wyniki[i];
					}
				}
		}
}

int main(int argc, char *argv[])
{
    double temp=0;
    int xi=-1;

	loadData();
	brb(DATA,IV,IC,0);

	cout<<"Max f(x)="<<maxc[0]<<" "<<endl;

	for(int i=1;i<IV+1;i++)
		cout<<"x"<<i<<"="<<maxc[i]<<" "<<endl;  
    return 0;
}