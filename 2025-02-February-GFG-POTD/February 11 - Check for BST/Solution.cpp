#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Utility function to check if the tree is a BST
bool isBSTUtil(Node* node, long long min, long long max) {
    if (node == nullptr) return true;

    if (node->data <= min || node->data >= max) return false;

    return isBSTUtil(node->left, min, node->data) && 
           isBSTUtil(node->right, node->data, max);
}

// Function to check whether a Binary Tree is BST or not
bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// Function to build a tree from input
Node* buildTree(vector<string>& ip) {
    if (ip.empty() || ip[0] == "N") return nullptr;

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        if (ip[i] != "N") {
            currNode->left = new Node(stoi(ip[i]));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            currNode->right = new Node(stoi(ip[i]));
            queue.push(currNode->right);
        }

        i++;
    }
    return root;
}

// Driver function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string s;
        getline(cin, s);
        vector<string> ip;
        stringstream ss(s);
        string temp;
        
        while (ss >> temp) {
            ip.push_back(temp);
        }

        Node* root = buildTree(ip);
        if (isBST(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        
        cout << "~" << endl;
    }
    return 0;
}
