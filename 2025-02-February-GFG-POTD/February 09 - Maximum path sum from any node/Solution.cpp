#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure
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
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root) {
        int res = INT_MIN;
        findMaxUtil(root, res);
        return res;
    }

private:
    // Helper function to compute max path sum
    int findMaxUtil(Node* node, int& res) {
        if (node == NULL) return 0;

        // Compute the maximum path sum of left and right subtrees
        int left = max(0, findMaxUtil(node->left, res));
        int right = max(0, findMaxUtil(node->right, res));

        // Update the global maximum path sum
        res = max(res, left + right + node->data);

        // Return the max path sum including the current node and one of its children
        return node->data + max(left, right);
    }
};

// Driver Code
int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;
    cout << obj.findMaxSum(root) << endl; // Output: 42

    return 0;
}
