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
        Node(string name);
        Node();
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
     };
}
