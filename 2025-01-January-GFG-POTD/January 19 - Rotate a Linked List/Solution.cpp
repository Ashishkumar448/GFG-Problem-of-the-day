#include <iostream>
#include <vector>
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
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Calculate the length of the linked list
        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Step 2: Calculate the effective number of rotations
        k = k % length;
        if (k == 0) {
            return head;
        }

        // Step 3: Traverse to the (k-th) node
        current = head;
        for (int i = 1; i < k; i++) {
            current = current->next;
        }

        // Step 4: The new head is the next node after the (k-th) node
        Node* newHead = current->next;

        // Step 5: Break the list into two parts and reconnect
        current->next = nullptr;

        // Step 6: Find the tail of the second part and connect it to the original head
        Node* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};

// Helper functions for the driver code
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Node* head = nullptr;
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (int i = 1; i < arr.size(); i++) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        int k;
        cin >> k;
        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }

    return 0;
}
