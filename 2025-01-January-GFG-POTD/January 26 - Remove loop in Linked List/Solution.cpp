#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to remove the loop in the linked list
void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node *slow = head, *fast = head;

    // Detecting the loop using Floyd's Cycle Detection Algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there is a loop
        if (slow == fast) break;
    }

    // If no loop is found, return
    if (fast == nullptr || fast->next == nullptr) return;

    // Find the start of the loop
    slow = head;
    if (slow != fast) {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    } else {
        // Special case: when the loop starts at the head
        while (fast->next != slow) {
            fast = fast->next;
        }
    }

    // Break the loop
    fast->next = nullptr;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Helper function to create a loop in the linked list
void makeLoop(Node* head, int x) {
    if (x == 0) return;

    Node* curr = head;
    Node* last = head;

    int currentPosition = 1;
    while (currentPosition < x) {
        curr = curr->next;
        currentPosition++;
    }

    while (last->next != nullptr) last = last->next;
    last->next = curr;
}

// Helper function to detect if a loop exists
bool detectLoop(Node* head) {
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise) {
        if (hare == nullptr || hare->next == nullptr) return false;
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return true;
}

// Main function for testing
int main() {
    int n, pos;
    cin >> n;

    int val;
    cin >> val;
    Node* head = newNode(val);
    Node* tail = head;

    for (int i = 1; i < n; ++i) {
        cin >> val;
        tail->next = newNode(val);
        tail = tail->next;
    }

    cin >> pos;
    makeLoop(head, pos);

    removeLoop(head);

    if (detectLoop(head)) {
        cout << "false\n";
    } else {
        cout << "true\n";
    }

    return 0;
}
