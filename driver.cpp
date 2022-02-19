#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int main()
{
    PersonNode* node = NULL;
    int count = 0;
    string some;
    PersonTree person;
    string username;
    vector<string> indoor;
    vector<string> outdoor;
    string name;
    string major;
    cout << "Welcome to Buffsearch, please enter the following info and we will find others like you!" << endl;
    cout << "1. Search for User" << endl;
    cout << "2. Add User" << endl;
    cout << "3. Find Similar Users" << endl;
    switch (count)
    {
    case 1: cout << "Enter a username to search for: ";
        cin >> username;
        node = person.searchUsername(username);
        if(node == NULL)
        {
            cout << "User does not exist." << endl;
        }
        break;
    case 2:cout << "Enter a Username:" << endl;
        cin >> username;
        while(node == NULL)
        {
            node = person.searchUsername(username);
            if(node != NULL)
            {
                cout << "User already exists, enter another username: " << endl;
                cin >> username;
            }
        }
        cout << "Enter your Name: ";
        cin >> name;
        cout << endl;
        cout << "Enter your Major: ";
        cin >> major;
        cout << endl;
        while(indoor.back() != "n")
        {
            cout << "Enter an indoor hobbie that you like to do: ";
            cin >> some;
            cout << endl;
            indoor.push_back(some);
        }
        while(outdoor.back() != "n")
        {
            cout << "Enter an indoor hobbie that you like to do: ";
            cin >> some;
            cout << endl;
            indoor.push_back(some);
        }
        indoor.pop_back();
        outdoor.pop_back();
        person.addtoPersonTree(NULL, username, name, major, indoor, outdoor);
    break;
    case 3: cout << "Enter a Username: ";
        cin >> username;
        node = person.searchUsername(username); // figure this out\if(node == NULL)
        if(node == NULL)
        {
            cout << "User does not exist." << endl;
        }
        else{
            person.similarNode(NULL, node->username, node->name, node->major, node->indoor, node->outdoor);
        }
    default: cout << "Wrong input, please try again." << endl;
        break;
    }

    return 0;
}