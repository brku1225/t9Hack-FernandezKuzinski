#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct PersonNode {
    string name;
    string major;
    vector<string> indoor;
    vector<string> outdoor;

    PersonNode* left  = NULL;
    PersonNode* right = NULL;
};
class PersonTree{
    private:
        PersonNode* root;
    public:
        PersonTree();
        ~PersonTree();

        void addtoPersonTree(string, string, vector<string>, vector<string>); // adding node to tree
        void similarNode(string, string, vector<string>, vector<string>); // finding node similar to you
        void searchTree(string); // searching tree by name (find you in tree)
        void printSimilarNode(string, string, vector<string>, vector<string>); // printing node info
        void destoryNode(PersonNode*);
}