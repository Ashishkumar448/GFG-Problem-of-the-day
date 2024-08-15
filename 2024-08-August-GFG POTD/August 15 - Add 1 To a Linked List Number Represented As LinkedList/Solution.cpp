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
    // Function to reverse the linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    // Function to add one to the linked list
    Node* addOne(Node* head) {
        // Reverse the linked list
        head = reverseList(head);
        
        Node* current = head;
        Node* prev = nullptr;
        int carry = 1;  // Initialize carry to 1 since we are adding 1
        
        // Traverse the list and add the carry
        while (current != nullptr) {
            int sum = current->data + carry;
            current->data = sum % 10;  // Update the node's value
            carry = sum / 10;  // Calculate the new carry
            prev = current;
            current = current->next;
        }
        
        // If there is still a carry after processing all nodes
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        
        // Reverse the linked list again to restore the original order
        return reverseList(head);
    }
};

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data;
        node = node->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        Node* head = new Node(x);
        Node* tail = head;
        for (int i = 1; i < n; i++) {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        Solution obj;
        head = obj.addOne(head);
        printList(head);
    }
    return 0;
}
