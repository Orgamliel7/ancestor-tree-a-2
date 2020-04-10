//
// Created by Tzach on 03/04/2020.
//
#include "FamilyTree.hpp"
#define COUNT 10
using namespace std;
using namespace family;
    Node::Node()
    {
        this->name = "";
        this->father = nullptr;
        this->mother = nullptr;
        this->depth=0;
        this->parent_type = "me";
    }
    Node::Node(string name)
    {
        this->name = name;
        father=mother=NULL;
        depth = 0;
        parent_type = "unknown";
    }
    Tree::Tree(string name)
    {
        root = new Node;
        root->name = name;
        root->father= nullptr;
        root->mother = nullptr;
        root->depth = 0;
        root->parent_type = "me";
    }
   /* take Node and name to search for */
   /*  */
    Node* Tree::findPos(Node* currentN, string name)
    {
        if (currentN->name.compare(name) == 0)
            return currentN;
        if (currentN->father->name.compare(name)==0)
            return currentN->father;
        if (currentN->mother->name.compare(name)==0)
            return currentN->mother;

        Node* fromFather = findPos(currentN->father, name);
        if(fromFather != NULL) return fromFather;
        Node* fromMother = findPos(currentN->mother, name);
        if(fromMother != NULL) return fromMother;

        return NULL;
    }
    Tree& Tree::addFather(string rootName, string newName)
    {
        Node *curr = findPos(this->root, rootName);
        if (curr != NULL)
        {
            if (curr->father == NULL)
            {
                curr->father = new Node(newName);
                curr->father->parent_type = "father";
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
            if (curr->mother == NULL)
            {
                curr->mother = new Node(newName);
                curr->mother->parent_type = "mother";
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
        print2DUtil(this->root, 0);
    };


    string getRelationName(int depth)
    {
        if (depth <= 1)
        {
            return "";
        }
        if (depth == 2)
        {
            return "grand";
        }
        string ans = "";
        for (int i = 2; i < depth; i++)
        {
            ans = ans + "great-";
        }
        ans = ans + "grand";
        return ans;
    }
    string Tree::relation(string who)
    {
        Node *curr = findPos(this->root, who);
        if (curr != NULL)
        {
            string ans = getRelationName(curr->depth);
            ans = ans + curr->parent_type; // should be parent type?
            return ans;
        }
        else
        {
            return "unrelated";
        }
    }


    void Tree::remove(string name)
    {

    }
    // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    void Tree::print2DUtil(Node *root, int space)
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
