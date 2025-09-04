/*
struct Node {
    int data;
    Node* next;
    Node(int key) : data(key), next(nullptr) {}
};
*/
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;
        Node dummy(0);
        dummy.next = head;
        Node* pre = &dummy;
        Node* end = &dummy;
        
        while (true) {
            int count = 0;
            while (end && count < k) {
                end = end->next;
                count++;
            }
            if (!end) break;
            Node* start = pre->next;
            Node* next = end->next;
            end->next = nullptr; // Temporarily break
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        if (pre->next != nullptr) {
            pre->next = reverse(pre->next);
        }
        return dummy.next;
    }
    
private:
    // Helper to reverse entire list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
