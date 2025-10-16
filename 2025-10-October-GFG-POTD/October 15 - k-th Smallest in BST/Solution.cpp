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
    int count = 0;
    int result = -1;

    void inorder(Node* root, int k) {
        if (root == nullptr) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        inorder(root->right, k);
    }

public:
    int KthSmallestElement(Node* root, int k) {
        inorder(root, k);
        return result;
    }
};
