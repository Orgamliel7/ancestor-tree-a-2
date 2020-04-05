//
// Created by shaharnik on 05/04/2020.
//

#ifndef ANCESTOR_TREE_A_FAMILYTREE_HPP
#define ANCESTOR_TREE_A_FAMILYTREE_HPP
#include <stdio.h>
#include <iostream>
using namespace std;
namespace family
{
    class Node{
    public:
        Node (string name);
        string name;
        Node* father;
        Node* mother;
        &Tree addRecF(string name, string father,Node* current);
        &Tree addRecM(string name, string mother,Node* current);
    };
    class Tree{
        Node* root;
    public:
        Tree (string s);
        string to_string();
        Tree addFather(string child, string father);
        Tree addMother(string child, string mother);
        string relation(string name);
        string find(string motherORfather);
        void display();
        Node remove(string s);

    };
}; // namespace family
#endif //ANCESTOR_TREE_A_FAMILYTREE_HPP
