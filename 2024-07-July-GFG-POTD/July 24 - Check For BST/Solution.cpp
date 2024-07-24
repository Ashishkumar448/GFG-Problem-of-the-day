#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

private:
    // Utility function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node* node, int min, int max) {
        // Base case: An empty tree is a BST
        if (node == nullptr) {
            return true;
        }

        // If this node violates the min/max constraint
        if (node->data < min || node->data > max) {
            return false;
        }

        // Otherwise, check the subtrees recursively,
        // tightening the min or max constraint
        return (isBSTUtil(node->left, min, node->data - 1) && 
                isBSTUtil(node->right, node->data + 1, max));
    }
};

// Function to build tree from string input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s; ) {
        ip.push_back(s);
    }

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

// Function to print inorder traversal (for debugging purposes)
void printInorder(Node* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution solution;
        if (solution.isBST(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
