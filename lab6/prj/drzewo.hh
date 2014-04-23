#ifndef DRZEWO_HH
#define DRZEWO_HH
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

/*!
 * \file
 * \brief Definiuje klase drzewo i jej metody
 */

/*! \brief Klasa drzewa poszukiwan binarnych
 * 
 */
class drzewo
{
private:
    class node
    {
        friend class drzewo;
        int value;
        node* left;
        node* right;

        /* Konstruktor wezla */

        node(int value1, node* left1 = NULL, node* right1 = NULL)
        {
            value = value1;
            left = left1;
            right = right1;
        }
        
    };


    /* Korzen */
    node* root;
      
      /* Metoda wstawiajaca wezel */
    void insertNode(node*&, int);
    
    public:
    drzewo();
    /* Metoda wstawiajaca wartosc */
    void insert(int value);
    /* Metoda wyszukujaca wartosc */
    int search(int value) const;  
};


#endif