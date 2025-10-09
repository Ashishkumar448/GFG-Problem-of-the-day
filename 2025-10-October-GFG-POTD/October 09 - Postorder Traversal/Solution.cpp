#include <bits/stdc++.h>
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

class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector<int> result;
        postOrderHelper(root, result);
        return result;
    }

private:
    void postOrderHelper(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        // 1️⃣ Visit left subtree
        postOrderHelper(node->left, result);
        // 2️⃣ Visit right subtree
        postOrderHelper(node->right, result);
        // 3️⃣ Visit node itself
        result.push_back(node->data);
    }
};
