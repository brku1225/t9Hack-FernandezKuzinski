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
    PersonNode* addHelper(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string>outdoor, vector<string> activities)
    {
        if(node == NULL)
        {
            PersonNode* person = new PersonNode;
            person->username = username;
            person->name = name;
            person->major = major;
            person->indoor = indoor;
            person->outdoor = outdoor;
            person->activities = activities;
            person->left = NULL;
            person->right = NULL;
            return person;
        }
        else if(username < node->username)
        {
            node->left = addHelper(node->left, username, name, major, indoor, outdoor, activities);
        }
        else if(username > node->username)
        {
            node->right = addHelper(node->right, username, name, major, indoor, outdoor, activities);
        }
        return node;
    }
    void PersonTree::addtoPersonTree(string username, string name, string major, vector<string> indoor, vector<string> outdoor, vector<string> activities) // adding node to tree
    {
        root = addHelper(root, username, name, major, indoor, outdoor, activities);
    }

    int isSimilar(PersonNode* currNode, vector<string> indoor, vector<string> outdoor, vector<string> activities)
    {
        int similar = 0;
        int act = 0;
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
        for(int i = 0; i < activities.size(); i++)
        {
            for(int j = i; j < activities.size(); j++)
            {
                if(activities[i] == currNode->outdoor[j])
                {
                    act++;
                }
            }
        }
        if(act > 0)
        {
            return -3;
        }
        else if(outdoor.size() > indoor.size() && currNode->outdoor.size() >= currNode->indoor.size() && similar > 1)
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
    void PersonTree::similarNodeHelper(PersonNode* node, string username, string name, string major, vector<string>indoor, vector<string> outdoor, vector<string> activities)
    {
        if(node == NULL)
        {
            return;
        }
        if(node->username != username)
        {
            int similar = isSimilar(node, indoor, outdoor, activities);
            if(similar == -3)
            {
                cout << "The following individual is in the same activity as you!" << endl;
                cout << "--------------------------------------------------------------" << endl;
                printSimilarNode(node);
            }
            else if(similar == -1)
            {
                cout << "The following individual has similar outdoor interests to you!" << endl;
                cout << "--------------------------------------------------------------" << endl;
                printSimilarNode(node);
            }
            else if(similar == -2)
            {
                cout << "The following individual has similar indoor interests to you!" << endl;
                cout << "-------------------------------------------------------------" << endl;
                printSimilarNode(node);
            }
            else if(similar >= 1)
            {
                printSimilarNode(node);
            }
        }
        similarNodeHelper(node->left, username, name, major, indoor, outdoor, activities);
        similarNodeHelper(node->right, username, name, major, indoor, outdoor, activities);
    }
    void PersonTree::similarNode(PersonNode* node, string username, string name, string major, vector<string> indoor, vector<string> outdoor, vector<string> activities) // finding node similar to you
    {
        similarNodeHelper(root, username, name, major, indoor, outdoor, activities);
    }
    void PersonTree::searchMajorHelper(PersonNode* node, string major, string username)
    {
        if(node == NULL)
        {
            return;
        }
        else if(node->major == major && node->username != username)
        {
            cout << "The following user has the same major." << endl;
            printSimilarNode(node);
        }
        searchMajorHelper(node->left, major, username);
        searchMajorHelper(node->right, major, username);
    }
    void PersonTree::searchMajor(string major, string username)
    {
        searchMajorHelper(root, major, username);
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
        cout << "Activities Interests: ";
        for(int i = 0; i < node->activities.size(); i++)
        {
            cout << node->activities[i] << endl;
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
            cout << "Activities Interests: ";
            for(int i = 0; i < node->activities.size(); i++)
            {
                cout << node->activities[i] << endl;
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