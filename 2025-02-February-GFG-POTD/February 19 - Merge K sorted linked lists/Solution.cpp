#include <bits/stdc++.h>
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

// Comparison function for the priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        // Add heads of all linked lists to the min-heap
        for (Node* head : arr) {
            if (head) {
                minHeap.push(head);
            }
        }

        // Dummy node for easier list construction
        Node* dummy = new Node(0);
        Node* current = dummy;

        while (!minHeap.empty()) {
            Node* smallestNode = minHeap.top();
            minHeap.pop();

            current->next = smallestNode;
            current = current->next;

            if (smallestNode->next) {
                minHeap.push(smallestNode->next);
            }
        }

        return dummy->next;
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

// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<Node*> lists(n);

        for (int i = 0; i < n; i++) {
            int val;
            Node* head = nullptr;
            Node* tail = nullptr;
            while (cin >> val) {
                if (val == -1) break; // Assuming -1 as the end of a linked list
                Node* newNode = new Node(val);
                if (!head) {
                    head = newNode;
                    tail = head;
                } else {
                    tail->next = newNode;
                    tail = tail->next;
                }
            }
            lists[i] = head;
        }

        Solution sol;
        Node* result = sol.mergeKLists(lists);
        printList(result);
        cout << "~" << endl;
    }

    return 0;
}
