#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* RemoveHalfNodes(Node* root) {
        if (!root) {
            return NULL;
        }

        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);

        if (!root->left && root->right) {
            Node* newRoot = root->right;
            delete root;
            return newRoot;
        }

        if (root->left && !root->right) {
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }

        return root;
    }
};

void printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(8);
    root->left->left = new Node(2);

    Solution solution;
    Node* new_root = solution.RemoveHalfNodes(root);
    printInOrder(new_root);  // Output: 2 5 8

    return 0;
}
