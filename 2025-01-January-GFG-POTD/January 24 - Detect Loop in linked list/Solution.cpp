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

void makeLoop(Node* head, Node* tail, int x) {
    if (x == 0) return;

    Node* curr = head;
    for (int i = 1; i < x; i++) {
        curr = curr->next;
    }

    tail->next = curr;
}

class Solution {
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        Node* slow = head; // Slow pointer
        Node* fast = head; // Fast pointer

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps

            // If slow and fast pointers meet, a loop is detected
            if (slow == fast) {
                return true;
            }
        }

        return false; // No loop detected
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, pos;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cin >> pos;

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;

            for (int i = 1; i < n; i++) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }

            makeLoop(head, tail, pos);
        }

        Solution sol;
        if (sol.detectLoop(head)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}
