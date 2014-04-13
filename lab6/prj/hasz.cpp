#include <list>
#include <iostream>
#include <string>
#include "hasz.hh"

using namespace std;


int hasztab::hash(string key)
{
    int n=key.size();
    int sum=0,val,index;
    for(int i=0;i<n;i++)
    {
        val=(int)key[i];
        sum+=val<<4;
    }
    index=sum%127;
    return index;
}


void hasztab::add(string key,int id)
{
    int index=hash(key);
    table[index].push_back(make_pair(key,id));
}


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
