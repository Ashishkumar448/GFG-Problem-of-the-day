/*
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Count nodes
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: If k is invalid
        if (k > n) return head;

        // Step 3: If same node from both sides
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth from start
        Node* xPrev = nullptr;
        Node* x = head;
        for (int i = 1; i < k; i++) {
            xPrev = x;
            x = x->next;
        }

        // Find kth from end => (n-k+1)th from start
        Node* yPrev = nullptr;
        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) {
            yPrev = y;
            y = y->next;
        }

        // Step 5: Swap previous pointers
        if (xPrev) xPrev->next = y;
        if (yPrev) yPrev->next = x;

        // Step 6: Swap next pointers
        Node* tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;

        // Step 7: Update head if needed
        if (k == 1) head = y;
        else if (k == n) head = x;

        return head;
    }
};
