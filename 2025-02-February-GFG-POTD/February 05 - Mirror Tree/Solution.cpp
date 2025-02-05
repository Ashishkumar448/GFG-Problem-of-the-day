#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;

        // Swap the left and right child nodes
        swap(node->left, node->right);

        // Recursively call for left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Function to build a tree from level order input
Node* buildTree(vector<string> &ip) {
    if (ip.empty() || ip[0] == "N") return NULL;

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

// Function to print level-order traversal of the tree
void levelOrder(Node* root) {
    if (!root) {
        cout << "N\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (!curr) {
            cout << "N ";
            continue;
        }
        cout << curr->data << " ";
        q.push(curr->left);
        q.push(curr->right);
    }
    cout << endl;
}

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

        Solution obj;
        obj.mirror(root);
        levelOrder(root);
        cout << "~" << endl;
    }

    return 0;
}
