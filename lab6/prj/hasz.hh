#ifndef HASZTAB_HH
#define HASZTAB_HH
#include <list>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;



class hasztab
{
    list <pair<string,int> > table[127];

    public:
        int hash(string key);
        void add(string key, int v);
        void find(string key);     
};
   
#endif