#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* insert(Node* head, int data) {
    Node* temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        return head;
    } else {
        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = temp;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    bool isLengthEven(Node* head) {
        Node* current = head;
        bool isEven = true;

        while (current != nullptr) {
            isEven = !isEven;
            current = current->next;
        }
        return isEven;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        Node* head = nullptr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int data;
        while (ss >> data) {
            head = insert(head, data);
        }

        Solution solution;
        bool f = solution.isLengthEven(head);
        cout << (f ? "true" : "false") << endl;

        cout << "~" << endl;  // delimiter similar to Java code
    }

    return 0;
}
