#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    pair<Node*, Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        Node* curr = root;

        while (curr != nullptr) {
            if (curr->data == key) {
                // Predecessor
                if (curr->left != nullptr) {
                    Node* temp = curr->left;
                    while (temp->right != nullptr)
                        temp = temp->right;
                    pre = temp;
                }
                // Successor
                if (curr->right != nullptr) {
                    Node* temp = curr->right;
                    while (temp->left != nullptr)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (key < curr->data) {
                suc = curr;
                curr = curr->left;
            }
            else {
                pre = curr;
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};

// Example usage
// You need to write your own BST construction and I/O based on the input format.
