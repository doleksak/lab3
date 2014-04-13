#include "drzewo.hh"
#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

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


drzewo::drzewo()
{
    this->root = NULL;
}

void drzewo::insert(int value)
{
    insertNode(root, value);
}

bool drzewo::search(int value) const
{
    node* tree = root;
    
    while (tree)
    {
        if (tree->value == value)
            return true;
        
        else if(value < tree->value)
            tree = tree->right;
        
        else
            tree = tree->right;
    }
    return false;
}
