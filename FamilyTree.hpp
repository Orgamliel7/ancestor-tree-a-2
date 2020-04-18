//
// Created by tzach on 03/04/2020.
//
#pragma once
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>
#include <cmath>
#include <cassert>
namespace family{
    class Node{
    public:
        string name;
        Node* father;
        Node* mother;
        Node *child;
        int height;
        string parent_type;
        string relation;
        Node(string name);
        Node();
        void setRelation(string relation)
        {
            this->relation = relation;
        }
        string getRelation()
        {
            return this->relation;
        }
        void setHeight(int h)
        {
            this->height=h;
        };
        int getHeight()
        {
            return this->height;
        }
        string getParentType()
        {
            return this->parent_type;
        };
        void setParentType(string type)
        {
            this->parent_type=type;
        };
    };
    class Tree{
    public:
        Node* root;
    public:
        Tree(string name);
        Tree& addFather(string rootName, string name2);
        Tree& addMother(string rootName, string name2);
        void display();
        std::string relation(string name);
        std::string find(string name);
        void remove(string name);
        Node * findPos(Node *currentN, string name);
        Node* findPosByType(Node* currentN, string name);
        void print2DUtil(Node *root, int space);
        Node* getRoot(){ return this->root;}
        void deleteSubTree(Node *&node);
        ~Tree();
    };
}

