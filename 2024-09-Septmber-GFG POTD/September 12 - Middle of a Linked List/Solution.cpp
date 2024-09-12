#include <iostream>
#include <sstream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to find the middle of the linked list
int getMiddle(Node* head) {
    if (head == nullptr) {
        return -1; // Return -1 if the list is empty.
    }

    Node* slow = head;
    Node* fast = head;

    // Move slow by 1 step and fast by 2 steps until fast reaches the end.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow will be at the middle of the list.
    return slow->data;
}

// Utility function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t > 0) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        ss >> x;
        Node* head = new Node(x);
        Node* tail = head;

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        cout << getMiddle(head) << endl;
        // printList(head); // Uncomment to print the list.
        t--;
    }

    return 0;
}
