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
        else if (username < node->username)
        {
            node = helperUsername(node->left, username);
        }
        else if(username > node->username)
        {
            node = helperUsername(node->right, username);
        }
        return node;
    }
    PersonNode* PersonTree::searchUsername(string username) // searching tree by name (find you in tree)
    {
        PersonNode* some = helperUsername(root, username);
        return some;
    }
    PersonNode* addHelper(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string>outdoor)
    {
        if(node == NULL)
        {
            PersonNode* person = new PersonNode;
            person->username = username;
            person->name = name;
            person->major = major;
            person->indoor = indoor;
            person->outdoor = outdoor;
            person->left = NULL;
            person->right = NULL;
            return person;
        }
        else if(username < node->username)
        {
            node->left = addHelper(node->left, username, name, major, indoor, outdoor);
        }
        else if(username > node->username)
        {
            node->right = addHelper(node->right, username, name, major, indoor, outdoor);
        }
        return node;
    }
    void PersonTree::addtoPersonTree(string username, string name, string major, vector<string> indoor, vector<string> outdoor) // adding node to tree
    {
        root = addHelper(root, username, name, major, indoor, outdoor);
    }

    int isSimilar(PersonNode* currNode, vector<string> indoor, vector<string> outdoor)
    {
        int similar = 0;
        for(int i = 0; i < indoor.size(); i++)
        {
            for(int j = i; j < indoor.size(); j++)
            {
                if(indoor[i] == currNode->indoor[j])
                {
                    similar++;
                }
            }
        }
        for(int i = 0; i < outdoor.size(); i++)
        {
            for(int j = i; j < outdoor.size(); j++)
            {
                if(outdoor[i] == currNode->outdoor[j])
                {
                    similar++;
                }
            }
        }
        if(outdoor.size() > indoor.size() && currNode->outdoor.size() >= currNode->indoor.size() && similar > 1)
        {
            return -1;
        }
        else if(indoor.size() > outdoor.size() && currNode->indoor.size() >= currNode->outdoor.size() && similar > 1)
        {
            return -2;
        }
        else if(similar >= 1)
        {
            cout << "The following individual has some shared interests as yourself!" << endl;
            cout << "------------------------------------------------------" << endl;
        }
        return similar;
    }
    void PersonTree::similarNodeHelper(PersonNode* node, string username, string name, string major, vector<string>indoor, vector<string> outdoor)
    {
        if(node == NULL)
        {
            return;
        }
        if(node->username != username)
        {
            int similar = isSimilar(node, indoor, outdoor);
            if(similar == -1)
            {
                cout << "The following individual has similar interests to you!" << endl;
                cout << "------You Both like Outdoors Activities more than Indoors---------" << endl;
                printSimilarNode(node);
            }
            else if(similar == -2)
            {
                cout << "The following individual has similar interests to you!" << endl;
                cout << "------You Both like Indoors Activities more than Outdoors---------" << endl;
                printSimilarNode(node);
            }
            else if(similar >= 1)
            {
                printSimilarNode(node);
            }
        }
        similarNodeHelper(node->left, username, name, major, indoor, outdoor);
        similarNodeHelper(node->right, username, name, major, indoor, outdoor);
    }
    void PersonTree::similarNode(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string> outdoor) // finding node similar to you
    {
        similarNodeHelper(root, username, name, major, indoor, outdoor);
    }
    void PersonTree::printSimilarNode(PersonNode* node) // printing node info
    {
        cout << "------------------------------------------------------" << endl;
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
    }
    void printHelper(PersonNode* node)
    {
        if(node == NULL)
        {
            return;
        }
        else{
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
        printHelper(node->left);
        printHelper(node->right);
    }
    void PersonTree::print()
    {
        printHelper(root);
    }