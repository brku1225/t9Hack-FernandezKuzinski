#include <iostream>
#include <fstream>
#include <sstream>
#include "BinaryTree.hpp"
using namespace std;

void bulkAdd(PersonTree &person, string fileName, string username, string name, string major, vector<string> indoor, vector<string> outdoor)
{
    int iterator = 0;
    int lin = 0;
    string line = "";
    string sub = "";
    ifstream file;
    file.open(fileName);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            if(lin == 0) // skipping the first line
            {
                line.erase();
                lin++;
            }
            else{
                stringstream ss(line);
                iterator = 0;
                while(getline(ss, sub, ','))
                {
                    if(iterator == 0)
                    {
                        cout<< sub <<endl;
                        username = sub;
                        iterator++;
                    }
                    else if(iterator == 1)
                    {
                        name = sub;
                        iterator++;
                    }
                    else if(iterator == 2)
                    {
                        major = sub;
                        iterator++;
                    }
                    else if(sub[0] == ':')
                    {
                        sub.erase(0,1);
                        indoor.push_back(sub);
                    }
                    else if(sub[0] == ';')
                    {
                        sub.erase(0,1);
                        outdoor.push_back(sub);
                    }
                }
                person.addtoPersonTree(NULL, username, name, major, indoor, outdoor);
            }
        }
    }
    else{
        cout << "Failed to fill database." << endl;
    }
}

int main()
{
    PersonTree person = PersonTree();
    PersonNode* node = new PersonNode();
    string filename = "individuals.csv";
    int count = 0;
    string some;
    string username;
    vector<string> indoor;
    vector<string> outdoor;
    string name;
    string major;
    bulkAdd(person, filename, username, name, major, indoor, outdoor);
    cout << "Welcome to Buffsearch, please enter the following info and we will find others like you!" << endl;
    while(count != 4)
    {
        cout << endl;
        cout << "1. Search for User" << endl;
        cout << "2. Add User" << endl;
        cout << "3. Find Similar Users" << endl;
        cout << "4. Exit" << endl;
        cin >> count;
        cout << endl;
        switch (count)
        {
        case 1: cout << "Enter a username to search for: ";
            cin >> username;
            node = person.searchUsername(username);
            if(node == NULL)
            {
                cout << "User does not exist." << endl;
            }
            else{
                cout << "----------- Profile------------" << endl;
                person.printSimilarNode(node);
            }
        break;
        case 2:cout << "Enter a Username: ";
            cin >> username;
            /*while(node == NULL)
            {
                node = person.searchUsername(username);
                if(node != NULL)
                {
                    cout << "User already exists, enter another username: " << endl;
                    cin >> username;
                }
            }*/
            cout << endl;
            do
            {
                cout << "Enter your Name: ";
                getline(cin, name);
                if(name == "")
                {
                    cout << "Please input a name." << endl;
                }
            } while (name == "");
            cout << endl;
            cout << "Enter your Major: ";
            getline(cin, major);
            cout << endl;
            do
            {
                cout << "Enter an indoor hobbie that you like to do (enter 'n' to stop): ";
                getline(cin, some);
                cout << endl;
                if(some != "n")
                {
                    indoor.push_back(some);
                }
            }while(some != "n");
            do
            {
                cout << "Enter an outdoor hobbie that you like to do (enter 'n' to stop): ";
                getline(cin, some);
                cout << endl;
                if(some != "n")
                {
                    outdoor.push_back(some);
                }
            }while(some != "n");
            person.addtoPersonTree(NULL, username, name, major, indoor, outdoor);
            if(node != NULL)
            {
                cout << "Your User has been added to the directory!" << endl;
            }
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
        case 4: cout << "Thanks for using our services, we will now proceed to hack your computer. Have a lovely day!" << endl;
            cout << endl;
        break;

        default: cout << "Wrong input, please try again." << endl;
            break;
        }
    }

    return 0;
}