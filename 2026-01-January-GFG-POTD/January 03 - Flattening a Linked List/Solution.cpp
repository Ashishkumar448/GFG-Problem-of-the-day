/*
struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
public:
    // Merge two sorted linked lists using bottom pointer
    Node* merge(Node* a, Node* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;

        Node* result;

        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // ignore next pointer
        return result;
    }

    // Flatten the linked list
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL)
            return root;

        // Recursively flatten the list to the right
        root->next = flatten(root->next);

        // Merge current list with flattened list
        root = merge(root, root->next);

        return root;
    }
};
