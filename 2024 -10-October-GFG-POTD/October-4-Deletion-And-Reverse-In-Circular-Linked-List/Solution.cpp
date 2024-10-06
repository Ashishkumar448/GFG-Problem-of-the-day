//{ Driver Code Starts
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head)
            return head;  // If list is empty or has only one node
        
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev;  // Fix the new head
        head = prev;
        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (head == NULL)
            return NULL;  // If the list is empty

        // If the node to be deleted is the only node
        if (head->data == key && head->next == head) {
            return NULL;
        }

        Node* last = head;
        Node* d = NULL;

        // If head is to be deleted
        if (head->data == key) {
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = last->next;
            return head;
        }

        // Traverse to find the node to delete
        while (last->next != head && last->next->data != key) {
            last = last->next;
        }

        // If the node to be deleted is found
        if (last->next->data == key) {
            d = last->next;
            last->next = d->next;
        }

        return head;
    }
};

// Helper function to print the list
void printList(Node* head) {
    if (head == NULL) {
        cout << "empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < n; i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head;  // Make the list circular

        Solution obj;
        Node* current = obj.deleteNode(head, key);
        Node* rev = obj.reverse(current);
        printList(rev);
    }

    return 0;
}
// } Driver Code Ends
