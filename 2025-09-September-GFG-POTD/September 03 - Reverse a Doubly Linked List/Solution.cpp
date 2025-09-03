#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) return head; // base case

        Node* curr = head;
        Node* temp = NULL;

        // Traverse and swap prev & next
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move forward (which is prev now)
        }

        // Adjust head to new head
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};
