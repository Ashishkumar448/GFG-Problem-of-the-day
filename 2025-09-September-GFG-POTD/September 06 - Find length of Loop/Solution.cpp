/*
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};
*/

class Solution {
public:
    int lengthOfLoop(Node* head) {
        if (head == nullptr) return 0;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd's cycle detection
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            if (slow == fast) {
                // Loop found, count loop length
                return countLoopLength(slow);
            }
        }

        // No loop
        return 0;
    }

private:
    int countLoopLength(Node* meetingPoint) {
        int count = 1;
        Node* current = meetingPoint->next;

        while (current != meetingPoint) {
            count++;
            current = current->next;
        }

        return count;
    }
};
