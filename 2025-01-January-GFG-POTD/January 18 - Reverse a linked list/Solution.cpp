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

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;  // Store the next node
        current->next = prev;            // Reverse the link
        prev = current;                  // Move prev one step forward
        current = nextNode;              // Move current one step forward
    }

    return prev;  // prev will be the new head
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node(value);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        head = reverseList(head);
        printList(head);

        cout << "~" << endl;
    }

    return 0;
}
