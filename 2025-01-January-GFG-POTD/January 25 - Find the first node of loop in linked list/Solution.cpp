#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    Node* findFirstNode(Node* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd's Cycle Detection Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the start of the loop
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // The first node in the loop
            }
        }

        // No loop found
        return nullptr;
    }
};

void makeLoop(Node* head, Node* tail, int x) {
    if (x == 0) return;

    Node* curr = head;
    for (int i = 1; i < x; i++) curr = curr->next;

    tail->next = curr;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < n; i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        makeLoop(head, tail, k);

        Solution obj;
        Node* ans = obj.findFirstNode(head);
        if (ans != nullptr) {
            cout << ans->data << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
