class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr;              // possible predecessor
                curr = curr->right;
            } 
            else if (curr->data > key) {
                suc = curr;              // possible successor
                curr = curr->left;
            } 
            else {
                // predecessor = max in left subtree
                if (curr->left != NULL) {
                    Node* temp = curr->left;
                    while (temp->right != NULL) {
                        temp = temp->right;
                    }
                    pre = temp;
                }
                
                // successor = min in right subtree
                if (curr->right != NULL) {
                    Node* temp = curr->right;
                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    suc = temp;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};
