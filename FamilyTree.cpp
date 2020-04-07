//
// Created by Tzach on 03/04/2020.
//
#include "FamilyTree.hpp"
using namespace std;
using namespace family;
    Node::Node()
    {
        this->name = "";
        this->father = nullptr;
        this->mother = nullptr;
    }
    Node::Node(string name)
    {
        this->name = name;
        father=mother=NULL;
    }
    Tree::Tree(string name)
    {
        root = new Node;
        root->name=name;
        root->father= nullptr;
        root->mother = nullptr;
    }
    Node* Tree::findPos(Node* currentN, string name)
    {
        if (this->root->name.compare(name) == 0)
        {
            return this->root;
        }
        if (this->root->father->name.compare(name)==0)
            return this->root->father;
        if (this->root->mother->name.compare(name)==0)
            return this->root->mother;
        else{
            currentN = this->root;
            Node* fromFather = findPos(currentN->father, name);
            if(fromFather != NULL) return fromFather;
            Node* fromMother = findPos(currentN->mother, name);
            if(fromMother != NULL) return fromMother;
        }
        return NULL;
    }
    Tree& Tree::addFather(string rootName, string newName)
    {
        Node *curr = findPos(this->root, rootName);
        if (curr != NULL)
        {
            if (this->root->father == NULL)
            {
                this->root->father = new Node(newName);
            }
            else
            {
                string test = "'" + rootName + "' already have a father!!";
                throw invalid_argument(test);
            }
        }
        else // we didn't find the root name
        {
            string test = "Could'nt find '" + rootName + "'";
            throw invalid_argument(test);
        }
        return *this;
    };
    Tree& Tree::addMother(string rootName, string newName)
    {
        Node *curr = findPos(this->root, rootName);
        if (curr != NULL)
        {
            if (this->root->mother == NULL)
            {
                this->root->mother = new Node(newName);
            }
            else
            {
                string test = "'" + rootName + "' already have a mother!!";
                throw invalid_argument(test);
            }
        }
        else // we didn't find the root name
        {
            string test = "Could'nt find '" + rootName + "'";
            throw invalid_argument(test);
        }
        return *this;
    };
    void Tree::display()
    {
        if (this->root->mother != NULL)
        {
            cout << this->root->mother->name;
        }
        cout << this->root->name << endl;
        if (this->root->father != NULL)
        {
            cout<< this->root->father->name;
        }
    };
    string Tree::relation(string name)
    {
        return "";
    };

    void Tree::remove(string name)
    {

    };
