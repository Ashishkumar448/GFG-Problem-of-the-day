#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper struct to store include/exclude sums
    struct Pair {
        int include;
        int exclude;
        Pair(int i, int e) : include(i), exclude(e) {}
    };

    int getMaxSum(Node* root) {
        Pair res = solve(root);
        return max(res.include, res.exclude);
    }

private:
    Pair solve(Node* node) {
        if (node == NULL)
            return Pair(0, 0);

        Pair left = solve(node->left);
        Pair right = solve(node->right);

        int include = node->data + left.exclude + right.exclude;
        int exclude = max(left.include, left.exclude) + max(right.include, right.exclude);

        return Pair(include, exclude);
    }
};

// Example usage
/*
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    cout << obj.getMaxSum(root) << endl; // Output: 16
}
*/
