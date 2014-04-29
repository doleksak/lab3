#ifndef HASZTAB_HH
#define HASZTAB_HH
#include <list>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;


/*!
 * \file
 * \brief Definiuje klase hasztab i jej metody
 */

/*! \brief Klasa tablicy mieszajacej
 * 
 */
class hasztab
{
    list <pair<string,int> > table[7]; //100027

    public:
        int hash(string key);
        void add(string key, int v);
        void find(string key);     
};
   
#endif