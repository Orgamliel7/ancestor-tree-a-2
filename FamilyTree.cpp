//
// Created by shaharnik on 05/04/2020.
//

#include "FamilyTree.hpp"
#include <stdio.h>
#include <iostream>
#define COUNT  10;
using namespace std;
namespace family
{
    Node::Node(string name) {
        this->name = name;
    }

    Tree::Tree(string name) {
        Node n(name);
        this->root = &n;
    }






    void Tree::display()
    {
        print2DUtil(this, 0);
    }
    // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    void Tree::print2DUtil(Tree *root, int space)
    {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2DUtil(root->father, space);

        // Print current node after space
        // count
        cout<<endl;
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<root->name<<"\n";

        // Process left child
        print2DUtil(root->mother, space);
    }


}