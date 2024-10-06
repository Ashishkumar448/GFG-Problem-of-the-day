#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    long long multiplyTwoLists(Node* first, Node* second) {
        const long long MOD = 1000000007;
        long long num1 = 0, num2 = 0;

        // Convert first linked list into a number
        while (first != NULL) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }

        // Convert second linked list into a number
        while (second != NULL) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }

        // Return the product of both numbers modulo 10^9 + 7
        return (num1 * num2) % MOD;
    }
};

// Helper functions for linked list manipulation
void push(Node*& head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = head_ref;
    head_ref = new_node;
}

void reverse(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* first = NULL;
        Node* second = NULL;

        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int value;
        while (ss >> value) {
            push(first, value);
        }

        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> value) {
            push(second, value);
        }

        reverse(first);
        reverse(second);

        Solution ob;
        cout << ob.multiplyTwoLists(first, second) << endl;
    }

    return 0;
}
