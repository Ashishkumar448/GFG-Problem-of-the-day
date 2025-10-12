#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
    int moves = 0;

    int dfs(Node* node) {
        if (!node) return 0;

        int leftBalance = dfs(node->left);
        int rightBalance = dfs(node->right);

        moves += abs(leftBalance) + abs(rightBalance);

        // Return current node’s balance
        return node->data + leftBalance + rightBalance - 1;
    }

public:
    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
