#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* rotate(Node* head, int k) {
        // If the list is empty, has only one node, or no rotation is needed
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Compute the length of the linked list
        Node* current = head;
        int length = 1;
        while (current->next != nullptr) {
            current = current->next;
            length++;
        }

        // Adjust k if it is greater than or equal to the length
        k = k % length;
        if (k == 0) return head; // No need to rotate if k is 0 after modulus operation

        // Traverse to the node just before the (k+1)th node
        current->next = head; // Connect the last node to the head to make it circular
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // The new head will be the next node after the new tail
        Node* newHead = newTail->next;

        // Break the circular list to make the rotated list
        newTail->next = nullptr;

        return newHead;
    }
};

// Utility function to print a linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(9);

    int k = 3;

    Solution ob;
    head = ob.rotate(head, k);
    printList(head);

    return 0;
}
