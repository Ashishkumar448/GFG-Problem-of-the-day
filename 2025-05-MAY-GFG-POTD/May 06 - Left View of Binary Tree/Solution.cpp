#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    string val;
    while (iss >> val) ip.push_back(val);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        if (ip[i] != "N") {
            currNode->left = new Node(stoi(ip[i]));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            currNode->right = new Node(stoi(ip[i]));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> leftView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            if (i == 0)
                result.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> view = leftView(root);
        for (int val : view) {
            cout << val << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
