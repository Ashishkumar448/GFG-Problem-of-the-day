#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int sum;

    Solution() {
        sum = 0;
    }

    void transformTree(Node* root) {
        sum = 0; // Reset before starting
        transform(root);
    }

private:
    void transform(Node* root) {
        if (root == nullptr)
            return;

        // Traverse right subtree first (larger values)
        transform(root->right);

        // Process current node
        int temp = root->data;
        root->data = sum;
        sum += temp;

        // Traverse left subtree (smaller values)
        transform(root->left);
    }
};
