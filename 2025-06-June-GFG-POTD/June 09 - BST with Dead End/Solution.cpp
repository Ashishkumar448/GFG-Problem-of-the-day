/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    bool isDeadEnd(Node* root) {
        return helper(root, 1, INT_MAX);
    }

private:
    bool helper(Node* node, int min, int max) {
        if (node == nullptr)
            return false;

        if (min == max)
            return true;

        return helper(node->left, min, node->data - 1) ||
               helper(node->right, node->data + 1, max);
    }
};
