#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        // Step 1: Add Root (Only if it's not a leaf)
        if (!isLeaf(root)) result.push_back(root->data);

        // Step 2: Left Boundary (excluding leaf nodes)
        addLeftBoundary(root->left, result);

        // Step 3: Leaf Nodes
        addLeaves(root, result);

        // Step 4: Right Boundary (excluding leaf nodes, reverse order)
        vector<int> rightBoundary;
        addRightBoundary(root->right, rightBoundary);
        reverse(rightBoundary.begin(), rightBoundary.end());
        result.insert(result.end(), rightBoundary.begin(), rightBoundary.end());

        return result;
    }

private:
    // Function to check if a node is a leaf node
    bool isLeaf(Node* node) {
        return (node->left == nullptr && node->right == nullptr);
    }

    // Function to add left boundary nodes (excluding leaf nodes)
    void addLeftBoundary(Node* node, vector<int>& result) {
        while (node) {
            if (!isLeaf(node)) result.push_back(node->data);
            node = (node->left) ? node->left : node->right;
        }
    }

    // Function to add all leaf nodes in left-to-right order
    void addLeaves(Node* node, vector<int>& result) {
        if (!node) return;
        if (isLeaf(node)) {
            result.push_back(node->data);
            return;
        }
        addLeaves(node->left, result);
        addLeaves(node->right, result);
    }

    // Function to add right boundary nodes (excluding leaf nodes)
    void addRightBoundary(Node* node, vector<int>& result) {
        while (node) {
            if (!isLeaf(node)) result.push_back(node->data);
            node = (node->right) ? node->right : node->left;
        }
    }
};

// Utility function to build tree (similar to Java's buildTree function)
Node* buildTree(string str) {
    if (str.length() == 0 || str == "N") return nullptr;

    stringstream ss(str);
    string word;
    vector<string> nodes;
    while (ss >> word) nodes.push_back(word);

    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        Node* currNode = q.front();
        q.pop();

        string currVal = nodes[i++];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }

        if (i >= nodes.size()) break;
        currVal = nodes[i++];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
    }

    return root;
}

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution obj;
        vector<int> res = obj.boundaryTraversal(root);
        for (int num : res) cout << num << " ";
        cout << endl;
    }
    return 0;
}
