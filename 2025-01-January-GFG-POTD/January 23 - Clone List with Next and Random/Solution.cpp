#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) : data(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone nodes and place them next to original nodes
        Node* current = head;
        while (current) {
            Node* clonedNode = new Node(current->data);
            clonedNode->next = current->next;
            current->next = clonedNode;
            current = clonedNode->next;
        }

        // Step 2: Assign random pointers for cloned nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the original and cloned lists
        Node* original = head;
        Node* cloneHead = head->next;
        Node* cloneCurrent = cloneHead;

        while (original) {
            original->next = original->next->next;
            if (cloneCurrent->next) {
                cloneCurrent->next = cloneCurrent->next->next;
            }
            original = original->next;
            cloneCurrent = cloneCurrent->next;
        }

        return cloneHead;
    }
};
