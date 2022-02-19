#include "BinaryTree.hpp"

    PersonTree::PersonTree(){

    }
    PersonTree::~PersonTree(){

    }
    string PersonTree::searchTree(PersonNode* node, string name) // searching tree by name (find you in tree)
    {
        string other;
        if(node == NULL)
        {
            cout << "This name is not in the tree. Try adding yourself to the directory." << endl;
        }
        if(node->name == name)
        {
            return name;
        }
        other = searchTree(node->left, name);
        other = searchTree(node->right, name);
    }
    void PersonTree::addtoPersonTree(string, string, vector<string>, vector<string>) // adding node to tree
    {

    }
    void PersonTree::similarNode(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string> outdoor) // finding node similar to you
    {
        if(node == NULL)
        {
            return;
        }
        if(indoor.size() == node->indoor.size() || outdoor.size() == node->outdoor.size()) // figure something out
        {
            printSimilarNode(node->username, node->name, node->major, node->indoor, node->outdoor);
        }
        else{
            if(node->username > username)
            {
                similarNode(node->left, username, name, major, indoor, outdoor);
            }
            else if(node->username < username)
            {
                similarNode(node->right, username, name, major, indoor, outdoor);
            }
        }
    }
    void PersonTree::printSimilarNode(string username, string name, string major, vector<string> indoor, vector<string> outdoor) // printing node info
    {
        cout << "The following individual has similar interests to you!" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
        cout << "Major:" << major << endl;
        cout << "Indoor Interests: ";
        for(int i = 0; i < indoor.size(); i++)
        {
            cout << indoor[i] << endl;
        }
        cout << "Outdoor Interests: ";
        for(int i = 0; i < outdoor.size(); i++)
        {
            cout << outdoor[i] << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
    void PersonTree::destoryNode(PersonNode*) // might not do
    {

    }