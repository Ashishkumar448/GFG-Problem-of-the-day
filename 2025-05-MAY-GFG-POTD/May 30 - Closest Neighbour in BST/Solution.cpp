/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
*/

class Solution {
public:
    int findMaxForK(Node* root, int k) {
        int result = -1;
        while (root != nullptr) {
            if (root->data <= k) {
                result = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return result;
    }
};
