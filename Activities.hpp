#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.hpp"
#ifndef ACTIVITIES_HPP
#define ACTIVITIES_HPP
using namespace std;

struct ActNode {
    string name;
    vector<PersonNode*> attendees;

    ActNode* left  = NULL;
    ActNode* right = NULL;
};
class ActTree{
    private:
        ActNode* root;
    public:
        ActTree();
        ~ActTree();

        void addActivity(string, vector<PersonNode*>);
        ActNode* findActivity(string);
        void printAct(ActNode*);
        void joinAct(string, PersonNode*);
        void print();
};
#endif