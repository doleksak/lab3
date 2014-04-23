#include "drzewo.hh"
#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

/*!
 * \file
 * \brief Metody klasy drzewo
 *
 */

/*! \brief Metoda wstawiajaca wezel. Jezeli wartosc sie powtorzy, nie dokonuje sie zmian.
 *  Jeżeli wartosc mniejsza od rodzica, wstawiamy po lewej stronie.
 * 
 */
void drzewo::insertNode(node*& tree, int value)
{
    if (!tree)
    {
        tree = new node(value);
        return;
    }
    if (tree->value == value)
        return;
    
    if (value < tree->value)
    {
        insertNode(tree->left, value);
    }
    else
        insertNode(tree->right, value);
}

/*! \brief Do obiektu root klasy drzewo przypisujemy null
 * 
 */
drzewo::drzewo()
{
    this->root = NULL;
}

/*! \brief Metoda dodajaca element do drzewa
 * 
 */
void drzewo::insert(int value)
{
    insertNode(root, value);
}

/*! \brief Metoda wyszukujaca wartosc zaczynajac od korzenia, przesuwając sie tylko po odpowiednich lisciach.
 * Gdy wartosc mniejsza od liscia, przsuwamy sie po lewej stronie. 
 * 
 */
int drzewo::search(int value) const
{
    node* tree = root;
    int i=1;
    while (tree)
    {   
        if (tree->value == value)
            return i;
        
        else if(value < tree->value)
            tree = tree->left;
        
        else
            tree = tree->right;
            i++; 
    }
    return false;
}
