#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    void deleteAlt(Node* head) {
        if (head == nullptr) return;  // if the list is empty, nothing to do

        Node* current = head;

        // Traverse the list and delete every alternate node
        while (current != nullptr && current->next != nullptr) {
            // Skip the next node by linking current node to the one after the next
            current->next = current->next->next;
            // Move to the next non-deleted node
            current = current->next;
        }
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

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        vector<int> arr;
        string input;
        getline(cin, input);
        istringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        ob.deleteAlt(head);
        printList(head);
    }

    return 0;
}
