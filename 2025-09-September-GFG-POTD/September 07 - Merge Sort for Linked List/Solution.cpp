#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};

class Solution {
public:
    // Main merge sort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        // Step 1: Find middle
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;

        // Split
        middle->next = nullptr;

        // Recursively sort halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);

        // Merge sorted halves
        return sortedMerge(left, right);
    }

private:
    // Merge two sorted lists
    Node* sortedMerge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result = nullptr;
        if (a->data <= b->data) {
            result = a;
            result->next = sortedMerge(a->next, b);
        } else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    }

    // Find middle of list
    Node* getMiddle(Node* head) {
        if (!head) return head;

        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
