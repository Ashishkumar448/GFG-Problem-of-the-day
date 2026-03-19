// Structure of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    struct Info {
        int minVal, maxVal, size;
        bool isBST;

        Info(int minVal, int maxVal, int size, bool isBST) {
            this->minVal = minVal;
            this->maxVal = maxVal;
            this->size = size;
            this->isBST = isBST;
        }
    };

    int maxSize = 0;

    int largestBst(Node* root) {
        maxSize = 0;
        solve(root);
        return maxSize;
    }

    Info solve(Node* root) {
        // Base case
        if (root == NULL) {
            return Info(INT_MAX, INT_MIN, 0, true);
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check BST condition
        if (left.isBST && right.isBST && 
            root->data > left.maxVal && root->data < right.minVal) {

            int size = left.size + right.size + 1;
            maxSize = max(maxSize, size);

            int minVal = min(root->data, left.minVal);
            int maxVal = max(root->data, right.maxVal);

            return Info(minVal, maxVal, size, true);
        }

        // Not BST
        return Info(INT_MIN, INT_MAX, max(left.size, right.size), false);
    }
};
