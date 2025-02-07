#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

private:
    // Helper function for recursion
    void inorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorderHelper(node->left, result); // Visit left subtree
        result.push_back(node->data);      // Visit node
        inorderHelper(node->right, result); // Visit right subtree
    }
};

// Function to build a tree from input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s;) ip.push_back(s);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution sol;
        vector<int> res = sol.inOrder(root);
        for (int val : res) cout << val << " ";
        cout << endl;
    }
    return 0;
}
