#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> s1; // For levels to be printed right-to-left
        stack<Node*> s2; // For levels to be printed left-to-right

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            // Process s1 (right to left)
            while (!s1.empty()) {
                Node* curr = s1.top(); s1.pop();
                result.push_back(curr->data);
                if (curr->right) s2.push(curr->right);
                if (curr->left) s2.push(curr->left);
            }

            // Process s2 (left to right)
            while (!s2.empty()) {
                Node* curr = s2.top(); s2.pop();
                result.push_back(curr->data);
                if (curr->left) s1.push(curr->left);
                if (curr->right) s1.push(curr->right);
            }
        }

        return result;
    }
};
