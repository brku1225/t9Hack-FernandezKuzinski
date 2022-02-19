#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int main()
{
    int n = -1;
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
        n = person.searchUsername(username);
        break;
    
    default:
        break;
    }
    cout << "Enter a Username:" << endl;
    cin >> username;
    while(n == -1)
    {
        n = person.searchUsername(username);
        if(n == -1)
        {
            cout << "This Username is already taken, please enter a new one:" << endl;
            cin >> username;
        }
    }
    cout << "Enter your Name: ";
    cin >> name;
    cout << endl;
    cout << "Enter your Major: ";
    cin >> major;
    cout << endl;
    int i = 0;
    while(indoor.back() != "n")
    {
        cout << "Enter an indoor hobbie that you like to do: ";
        cin >> some;
        cout << endl;
        indoor.push_back(some);
        i++;
    }

    return 0;
}