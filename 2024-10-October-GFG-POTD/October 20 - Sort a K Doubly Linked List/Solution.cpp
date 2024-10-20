// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void push(DLLNode*& tail, int new_data) {
    DLLNode* newNode = new DLLNode(new_data);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    }
}

void printList(DLLNode* head) {
    if (head == nullptr) {
        return;
    }

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (head == nullptr) return nullptr;

        // Min heap (priority queue) to store DLLNodes
        priority_queue<DLLNode*, vector<DLLNode*>, function<bool(DLLNode*, DLLNode*)>> minHeap(
            [](DLLNode* a, DLLNode* b) { return a->data > b->data; });

        DLLNode* newHead = nullptr;
        DLLNode* last = nullptr;

        // Insert the first k+1 items into the min heap
        DLLNode* current = head;
        for (int i = 0; current != nullptr && i <= k; i++) {
            minHeap.push(current);
            current = current->next;
        }

        // Process the heap and form the sorted doubly linked list
        while (!minHeap.empty()) {
            DLLNode* minNode = minHeap.top();
            minHeap.pop();

            // Set the first node as the new head
            if (newHead == nullptr) {
                newHead = minNode;
                newHead->prev = nullptr;
                last = newHead;
            } else {
                // Link the new node at the end of the sorted list
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }

            // If there are more nodes in the original list, add them to the heap
            if (current != nullptr) {
                minHeap.push(current);
                current = current->next;
            }
        }

        // The last node's next should be null
        last->next = nullptr;

        return newHead;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);
        vector<int> arr;
        int val;
        while (iss >> val) {
            arr.push_back(val);
        }
        int k;
        cin >> k;

        DLLNode* head = new DLLNode(arr[0]);
        DLLNode* tail = head;

        for (int i = 1; i < arr.size(); i++) {
            push(tail, arr[i]);
            tail = tail->next;
        }

        Solution obj;
        DLLNode* sorted_head = obj.sortAKSortedDLL(head, k);
        printList(sorted_head);
    }
    return 0;
}
