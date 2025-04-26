#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    stringstream ss(str);
    string word;
    vector<string> ip;

    while (ss >> word) ip.push_back(word);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();

        if (ip[i] != "N") {
            curr->left = new Node(stoi(ip[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            curr->right = new Node(stoi(ip[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

bool isHeap(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);
    bool nullChildSeen = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left) {
            if (nullChildSeen || curr->left->data > curr->data)
                return false;
            q.push(curr->left);
        } else {
            nullChildSeen = true;
        }

        if (curr->right) {
            if (nullChildSeen || curr->right->data > curr->data)
                return false;
            q.push(curr->right);
        } else {
            nullChildSeen = true;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << (isHeap(root) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}
