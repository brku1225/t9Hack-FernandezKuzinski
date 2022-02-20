#include "Activities.hpp"
#include "BinaryTree.hpp"

ActTree::ActTree()
{
    root = NULL;
}
void destroyNode(ActNode *currNode)
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
ActTree::~ActTree()
{
    destroyNode(root);
    root = NULL;
}
ActNode* addHelper(ActNode* node, string name, vector<PersonNode*> attendees)
{
    if(node == NULL)
    {
        ActNode* act = new ActNode;
        act->name = name;
        act->attendees = attendees;
        act->left = NULL;
        act->right = NULL;
        return act;
    }
    else if(name < node->name)
    {
        node->left = addHelper(node->left, name, attendees);
    }
    else if(name > node->name)
    {
        node->right = addHelper(node->right, name, attendees);
    }
    return node;
}
void ActTree::addActivity(string name, vector<PersonNode*> attendees)
{
    root = addHelper(root, name, attendees);
}
ActNode* findHelper(ActNode* node, string name)
{
    if(node == NULL)
    {
        return node;
    }
    else if(node->name == name)
    {
        return node;
    }
    else if (name < node->name)
    {
        node = findHelper(node->left, name);
    }
    else{
        node = findHelper(node->right, name);
    }
    return node;
}
ActNode* ActTree::findActivity(string name)
{
    ActNode* node = findHelper(root, name);
    return node;
}
void ActTree::printAct(ActNode* node)
{
    cout << "-------------------------" << endl;
    cout << "Activity: " << node->name << endl;
    for(int i = 0; i < node->attendees.size(); i++)
    {
        cout << "Attendee of club: " << node->attendees[i]->name << ", " << node->attendees[i]->username << endl;
    }
    cout << endl;
}
void ActTree::joinAct(string act, PersonNode* some)
{
    ActNode* node = findHelper(root, act);
    if(node != NULL)
    {
        node->attendees.push_back(some);
    }
}
void printHelper(ActNode* node)
    {
        if(node == NULL)
        {
            return;
        }
        else{
            cout << "Activity: " << node->name << endl;
            if(node->attendees.empty())
            {
                cout << "There is no one in this activity." << endl;
            }
            for(int i = 0; i < node->attendees.size(); i++)
            {
                cout << "Attendee of Activity: " << node->attendees[i]->name << ", " << node->attendees[i]->username << endl;
            }
            cout << "------------------------------------------------------" << endl;
        }
        printHelper(node->left);
        printHelper(node->right);
    }
    void ActTree::print()
    {
        printHelper(root);
    }