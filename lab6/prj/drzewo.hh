#ifndef DRZEWO_HH
#define DRZEWO_HH
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class drzewo
{
private:
    class node
    {
        friend class drzewo;
        int value;
        node* left;
        node* right;
        node(int value1, node* left1 = NULL, node* right1 = NULL)
        {
            value = value1;
            left = left1;
            right = right1;
        }
        
    };

    node* root;
      
    void insertNode(node*&, int);
    
    public:
    drzewo();
    void insert(int value);
    bool search(int value) const;  
};


#endif