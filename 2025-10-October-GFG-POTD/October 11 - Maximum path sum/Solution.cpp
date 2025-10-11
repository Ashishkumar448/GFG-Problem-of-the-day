#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution {
    int res; // global variable to store maximum path sum

    int maxPathDown(Node* node) {
        if (node == nullptr) return 0;

        // Compute maximum path sum on left and right subtrees
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));

        // Update global result (max path sum through the current node)
        res = max(res, node->data + left + right);

        // Return max path sum going upward (only one branch)
        return node->data + max(left, right);
    }

public:
    int findMaxSum(Node* root) {
        res = INT_MIN;
        maxPathDown(root);
        return res;
    }
};
