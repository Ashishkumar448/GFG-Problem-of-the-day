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
    Node* removekeys(Node* root, int l, int r) {
        // Base case: if tree is empty
        if (root == nullptr)
            return nullptr;

        // Recur for left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        // If current node's value is smaller than l, 
        // discard left subtree and current node
        if (root->data < l)
            return root->right;

        // If current node's value is greater than r,
        // discard right subtree and current node
        if (root->data > r)
            return root->left;

        // Current node is in range
        return root;
    }
};
