#include "BinaryTree.hpp"

    PersonTree::PersonTree(){
        root = NULL;
    }

    void destroyNode(PersonNode *currNode)
    {
        if(currNode == NULL)
        {
            return;
        }
        else
        {
            destroyNode(currNode->left);
            destroyNode(currNode->right);

            delete currNode;
            currNode = NULL;
        }
    }
    PersonTree::~PersonTree(){
        PersonNode* node = root;
        destroyNode(node);
        root = NULL;
    }
    PersonNode* helperUsername(PersonNode* node, string username)
    {
        if(node == NULL)
        {
            return node;
        }
        else if(node->username == username)
        {
            return node;
        }
        else{
            if (username < node->username)
            {
                node->left = helperUsername(node->left, username);
            }
            if(username > node->username)
            {
                node->right = helperUsername(node->right, username);
            }
        }
        return node;
    }
    PersonNode* PersonTree::searchUsername(string username) // searching tree by name (find you in tree)
    {
        PersonNode* some = helperUsername(root, username);
        return some;
    }
    PersonNode* addHelper(PersonNode* currentNode, string username, string name, string major, vector<string> indoor, vector<string>outdoor)
    {
        if (currentNode == NULL)
        {
            PersonNode *person = new PersonNode();
            person->username = username;
            person->name = name;
            person->major = major;
            person->indoor = indoor;
            person->outdoor = outdoor;
            currentNode = person;
            return person;
        }
        if (username < currentNode->username)
        {
            currentNode->left = addHelper(currentNode->left, username, name, major, indoor, outdoor);
        }
        if (username > currentNode->username)
        {
            currentNode->right = addHelper(currentNode->right, username, name, major, indoor, outdoor);
        }
        return currentNode;
    }
    void PersonTree::addtoPersonTree(PersonNode *currentNode, string username, string name, string major, vector<string> indoor, vector<string> outdoor) // adding node to tree
    {
        if(root == NULL)
        {
            currentNode = addHelper(currentNode, username, name, major, indoor, outdoor);
            root = currentNode;
        }
        else{
            currentNode = addHelper(root, username, name, major, indoor, outdoor);
        }
    }
    void PersonTree::similarNode(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string> outdoor) // finding node similar to you
    {
        if(node == NULL)
        {
            node = root;
        }
        if(indoor.size() == node->indoor.size() || outdoor.size() == node->outdoor.size()) // figure something out
        {
            cout << "The following individual has similar interests to you!" << endl;
            cout << "------------------------------------------------------" << endl;
            printSimilarNode(node);
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
    void PersonTree::printSimilarNode(PersonNode* node) // printing node info
    {
        cout << "Username: " << node->username << endl;
        cout << "Name: " << node->name << endl;
        cout << "Major: " << node->major << endl;
        cout << "Indoor Interests: ";
        for(int i = 0; i < node->indoor.size(); i++)
        {
            cout << node->indoor[i] << endl;
        }
        cout << "Outdoor Interests: ";
        for(int i = 0; i < node->outdoor.size(); i++)
        {
            cout << node->outdoor[i] << endl;
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;
    }