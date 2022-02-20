#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BinaryTree.hpp"
#include "Activities.hpp"
using namespace std;

void bulkAdd(ActTree &tree, PersonTree &person, string fileName, string username, string name, string major, vector<string> indoor, vector<string> outdoor, vector<string> activities)
{
    int iterator = 0;
    int lin = 0;
    //PersonNode* other = new PersonNode;
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
                    else if(sub[0] == '~')
                    {
                        sub.erase(0,1);
                        activities.push_back(sub);
                    }
                }
                person.addtoPersonTree(username, name, major, indoor, outdoor, activities);
                PersonNode *other = person.searchUsername(username);
                if(!activities.empty() && other != NULL)
                {
                    for(int l = 0; l < activities.size(); l++)
                    {
                        tree.joinAct(activities[l], other);
                    }
                }
                while(!indoor.empty() && !outdoor.empty() && !activities.empty())
                {
                    indoor.pop_back();
                    outdoor.pop_back();
                    activities.pop_back();
                }
            }
        }
    }
    else{
        cout << "Failed to fill database." << endl;
    }
    file.close();
}
void bulkActivities(ActTree &act, string nameFile)
{
    int lin = 0;
    string line = "";
    vector<PersonNode*> activ;
    ifstream file;
    file.open(nameFile);
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
                act.addActivity(line, activ);
            }
        }
        file.close();
    }
    else{
        cout << "Failed to fill database." << endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: ./<program name> <Profiles file> <Activities file>" << endl;
        return 0;
    }
    else{
        ActNode* act = new ActNode;
        ActTree tree = ActTree();
        PersonTree person = PersonTree();
        PersonNode* node = new PersonNode;
        string filename = argv[1];
        string nameFile = argv[2];
        int count = 0;
        string some;
        string username;
        vector<string> indoor;
        vector<string> outdoor;
        vector<string> activities;
        string name;
        string major;
        bulkActivities(tree, nameFile);
        bulkAdd(tree, person, filename, username, name, major, indoor, outdoor, activities);
        cout << endl;
        cout << "Welcome to Buffsearch, please enter the following info and we will find others like you!" << endl;
        while(count != 9)
        {
            cout << endl;
            cout << "1. Search for User" << endl;
            cout << "2. Add User" << endl;
            cout << "3. Find Similar Users" << endl;
            cout << "4. Find Users with same Major" << endl;
            cout << "5. Show all Users" << endl;
            cout << "6. Search Activities" << endl;
            cout << "7. Join club" << endl;
            cout << "8. Print all clubs" << endl;
            cout << "9. Exit" << endl;
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
                    cout << "----------- Profile ------------" << endl;
                    person.printSimilarNode(node);
                }
            break;

            case 2:
                cout << "Enter a Username: ";
                cin >> username;
                do
                {
                    node = person.searchUsername(username);
                    if(node != NULL)
                    {
                        cout << "User already exists, enter another username: " << endl;
                        cin >> username;
                    }
                }while(node != NULL);
                cout << endl;
                cout << "Enter your Name: ";
                getline(cin, name);
                do
                {
                    if(name == "")
                    {
                        cout << "Please input a name." << endl;
                        getline(cin, name);
                    }
                } while (name == "");
                cout << endl;
                cout << "Enter your Major: ";
                getline(cin, major);
                cout << endl;
                do
                {
                    cout << "Enter an indoor hobbie that you like to do (enter 'n' to stop, please enter at least 1): ";
                    getline(cin, some);
                    cout << endl;
                    if(some != "n")
                    {
                        indoor.push_back(some);
                    }
                }while(some != "n" && outdoor.size() != 0);
                do
                {
                    cout << "Enter an outdoor hobbie that you like to do (enter 'n' to stop, please enter at least 1): ";
                    getline(cin, some);
                    cout << endl;
                    if(some != "n")
                    {
                        outdoor.push_back(some);
                    }
                }while(some != "n" && outdoor.size() != 0);
                do
                {
                    cout << "Enter an an activity that you attend (enter 'n' to stop, not required): ";
                    getline(cin, some);
                    cout << endl;
                    if(some != "n")
                    {
                        activities.push_back(some);
                    }
                }while(some != "n" && outdoor.size() != 0);
                person.addtoPersonTree(username, name, major, indoor, outdoor, activities);
                if(node != NULL)
                {
                    cout << "Your User has been added to the directory!" << endl;
                }
            break;

            case 3: cout << "Enter a Username: ";
                cin >> username;
                node = person.searchUsername(username);
                if(node == NULL)
                {
                    cout << "User does not exist." << endl;
                }
                else{
                    person.similarNode(NULL, node->username, node->name, node->major, node->indoor, node->outdoor, node->activities);
                }
            break;

            case 4: cout << "Enter a username to search for: ";
                cin >> username;
                node = person.searchUsername(username);
                if(node == NULL)
                {
                    cout << "User does not exist." << endl;
                }
                else{
                    person.searchMajor(node->major, node->username);
                }
            break;

            case 5: person.print();
            break;

            case 6: cout << "Enter name of Activity you would like to find: ";
                cin >> name;
                cout << endl;
                act = tree.findActivity(name);
                if(act == NULL)
                {
                    cout << "We do not have this activity in our directory." << endl;
                }
                else{
                    tree.printAct(act);
                }
            break;

            case 7: cout << "What Activity would you like to join: ";
                cin >> name;
                cout << endl;
                cout << "Enter your Username: ";
                cin >> username;
                cout << endl;
                node = person.searchUsername(username);
                if(node == NULL)
                {
                    cout << "User does not exist." << endl;
                }
                act = tree.findActivity(name);
                if(act == NULL)
                {
                    cout << "We do not have this activity in our directory." << endl;
                }
                else{
                    tree.joinAct(act->name, node);
                    cout << "You have successfully joined the activity " << name << "." << endl;
                    tree.printAct(act);
                    cout << endl;
                }
            break;
            case 8: tree.print();
            break;
            case 9: cout << "Thanks for using our services, we will now proceed to hack your computer. Have a lovely day!" << endl;
                cout << endl;
                person.~PersonTree();
                tree.~ActTree();
            break;

            default: cout << "Wrong input, please try again." << endl;
                break;
            }
        }
    }

    return 0;
}