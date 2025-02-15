#include <bits/stdc++.h>
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
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (root == NULL) return NULL;

        if (root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);

        if (root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);

        return root;
    }
};

int main() {
    // Example usage
    // You can implement the tree building logic similar to Java if needed.
    return 0;
}
