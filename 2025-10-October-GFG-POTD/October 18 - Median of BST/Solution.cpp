/* Structure of a Node */
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
    // Function to count total nodes in BST
    int countNodes(Node* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Helper for inorder traversal to find median
    int findMedianUtil(Node* root, int targetIndex, int &count) {
        if (root == nullptr) return -1;

        // Search left subtree
        int left = findMedianUtil(root->left, targetIndex, count);
        if (left != -1) return left;

        // Visit current node
        count++;
        if (count == targetIndex)
            return root->data;

        // Search right subtree
        return findMedianUtil(root->right, targetIndex, count);
    }

    int findMedian(Node* root) {
        if (root == nullptr) return 0;

        // Step 1: count total nodes
        int n = countNodes(root);

        // Step 2: find target index
        int targetIndex = (n % 2 == 0) ? n / 2 : (n + 1) / 2;

        // Step 3: second inorder traversal to get target element
        int count = 0;
        return findMedianUtil(root, targetIndex, count);
    }
};
