//
// Created by Shahar & Tzach on 03/04/2020.
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
        //if (currentN->father->name.compare(name)==0)
         //   return currentN->father;
       // if (currentN->mother->name.compare(name)==0)
       //     return currentN->mother;

       if (currentN->father != nullptr)
       {
           Node* fromFather = findPos(currentN->father, name);
           if(fromFather != NULL) return fromFather;
       }
        if (currentN->mother != nullptr)
        {
            Node* fromMother = findPos(currentN->mother, name);
            if(fromMother != NULL) return fromMother;
        }
        return NULL; // Not Found
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
        //printBT(this->root);
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
void RemoveRec2(Node* root)
{
    if (root == nullptr)
        return;

    //Delete Left and Right Subtree first
    RemoveRec2(root->father);
    RemoveRec2(root->mother);

    cout << "Deleting node: " << root->name << endl;
    root->father=root->mother = nullptr;

    // after deleting left and right subtree delete current node

    delete root;
    root = nullptr;
}
    void RemoveRec(Node* root)
    {
        if (root == nullptr)
            return;

        //Delete Left and Right Subtree first
        RemoveRec(root->father);
        RemoveRec(root->mother);

        cout << "Deleting node: " << root->name << endl;
        root->father=root->mother = nullptr;

        // after deleting left and right subtree delete current node

        delete root;
        root = nullptr;
    }
    /* Deletes a tree and sets the root as NULL */
    void deleteSubTree(Node** node_ref)
    {
        RemoveRec(*node_ref);
        *node_ref = nullptr;
    }
    void Tree::remove(string person_name)
    {
        Node* PersonToRemove = findPos(this->root,person_name);
        if (PersonToRemove == nullptr)
            throw runtime_error("The person doesn't exist in tree");
        if (PersonToRemove == this->root)
            throw runtime_error("Can't remove myself, the root of the tree");
        RemoveRec2(PersonToRemove);
        //deleteSubTree(&PersonToRemove);
        if (PersonToRemove == nullptr)
            cout << "tree successfully deleted!";

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
    // https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    void Tree::printBT(const std::string& prefix, const Node* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->name << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node->father, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node->mother, false);
        }
    }
    void Tree::printBT(const Node* node)
    {
        printBT("", node, false);
    }

    string Tree::find(string name)
    {

        return "k";
    }
