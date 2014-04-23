#include <list>
#include <iostream>
#include <string>
#include "hasz.hh"

using namespace std;


/*! \brief Funkcja haszujaca. Wykorzystuje dzielenie modulo, 
 * hash okreslony na podstawie dlugosci napisu i wartości jego znaków.
 * 
 */
int hasztab::hash(string key)
{
    int n=key.size();   //liczba znakow napisu
    int sum=0,val,index;
    for(int i=0;i<n;i++)
    {
        val=(int)key[i];
        sum+=val<<4;  //mnożenie val przez 2^4, dodanie i przypisanie do sum
    }
    index=sum%127; //reszta z dzielenia sum przez 127
    return index;
}

/*! \brief Metoda dodająca parę wartość, klucz do tablicy mieszającej
 * 
 */
void hasztab::add(string key, int id)
{
    int index=hash(key);
    table[index].push_back(make_pair(key,id));
}

/*! \brief Metoda pobiera wartość na podstawie zadanego klucza
 * 
 */
void hasztab::find(string key)
{
    int id=hash(key);
    list< pair<string,int> >::iterator itr=table[id].begin();
    if(!table[id].empty())
    {
        while(itr!=table[id].end())
        {
            if( (*itr).first==key )
                cout<<"Wartosc: "<<(*itr).second<<endl;
            itr++;
        }
    }
    else
    cout<<"Blad";
}
