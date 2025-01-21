#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int key) {
        data = key;
        next = nullptr;
    }
};

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;

        while (curr) {
            Node* groupPrev = nullptr;
            Node* groupCurr = curr;
            int count = 0;

            // Reverse the group
            while (curr && count < k) {
                Node* next = curr->next;
                curr->next = groupPrev;
                groupPrev = curr;
                curr = next;
                count++;
            }

            // Update the new head for the first group
            if (!newHead) newHead = groupPrev;

            // Connect previous group to the current reversed group
            if (tail) tail->next = groupPrev;

            // Move the tail pointer to the current group's tail
            tail = groupCurr;
        }

        return newHead;
    }
};

// Helper functions to test the code
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Input handling and driver code can be added here.
    return 0;
}
