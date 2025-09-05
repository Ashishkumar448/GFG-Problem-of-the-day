/*
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};
*/

class Solution {
public:
    Node* segregate(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // Dummy nodes for 0s, 1s, 2s
        Node* zeroD = new Node(-1);
        Node* oneD = new Node(-1);
        Node* twoD = new Node(-1);

        Node* zero = zeroD;
        Node* one = oneD;
        Node* two = twoD;

        Node* curr = head;

        // Partition into three lists
        while (curr != nullptr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect three lists
        zero->next = (oneD->next != nullptr) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;  // end of final list

        Node* newHead = zeroD->next;

        // Free dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};
