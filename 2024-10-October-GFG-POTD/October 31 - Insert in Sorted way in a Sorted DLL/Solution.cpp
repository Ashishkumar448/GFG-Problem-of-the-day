#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* sortedInsert(Node* head, int x) {
        Node* newNode = new Node(x);

        // Case 1: List is empty
        if (head == nullptr) {
            return newNode;
        }

        // Case 2: Insert at the beginning
        if (x <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode; // New head of the list
        }

        // Case 3: Traverse and find the appropriate position to insert
        Node* current = head;
        while (current->next != nullptr && current->next->data < x) {
            current = current->next;
        }

        // Case 4: Insert after 'current' node
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;

        return head; // Head remains the same
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t-- > 0) {
        string input;
        getline(cin, input);
        istringstream iss(input);

        Node* head = nullptr;
        Node* tail = nullptr;
        int x;
        while (iss >> x) {
            if (head == nullptr) {
                head = new Node(x);
                tail = head;
            } else {
                tail->next = new Node(x);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }

        int valueToInsert;
        cin >> valueToInsert;
        if (cin.peek() == '\n') cin.ignore(); // Ignore newline after valueToInsert

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);

        cout << "~" << endl;
    }

    return 0;
}
