/*
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: Empty list
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }

        Node* current = head;

        while (true) {
            // Case: Insert in between current and next
            if (current->data <= data && data <= current->next->data) {
                break;
            }

            // Case: At rotation point (max -> min)
            if (current->data > current->next->data) {
                if (data >= current->data || data <= current->next->data) {
                    break;
                }
            }

            current = current->next;

            // Completed full circle
            if (current == head) {
                break;
            }
        }

        newNode->next = current->next;
        current->next = newNode;

        // Return new head if newNode is smaller than head
        return (head->data <= data) ? head : newNode;
    }
};
