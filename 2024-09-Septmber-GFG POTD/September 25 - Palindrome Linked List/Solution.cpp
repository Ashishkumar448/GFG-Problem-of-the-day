// Initial Template for C++

#include <iostream>
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

class Solution {
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // A single node or empty list is always a palindrome.
        }

        // Step 1: Find the middle of the linked list.
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list.
        Node* secondHalf = reverse(slow);

        // Step 3: Compare the first and second half of the list.
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf; // To restore the list later (optional).
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Optional - Restore the list to its original form by reversing the second half again.
        reverse(secondHalfCopy);

        return true;
    }

    // Helper function to reverse the linked list.
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// Utility function to insert a node at the end of the linked list
Node* insert(Node* head, int data) {
    Node* temp = new Node(data);
    if (head == nullptr) {
        return temp;
    }
    Node* t = head;
    while (t->next != nullptr) {
        t = t->next;
    }
    t->next = temp;
    return head;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* head = nullptr;
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        int data;
        while (ss >> data) {
            head = insert(head, data);
        }
        Solution ob;
        if (ob.isPalindrome(head)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
