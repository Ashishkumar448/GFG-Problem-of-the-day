/*
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* addTwoLists(Node* head1, Node* head2) {

        // Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node* dummy = new Node(0);
        Node* curr = dummy;

        // Add digits
        while (head1 != NULL || head2 != NULL || carry != 0) {
            int sum = carry;

            if (head1 != NULL) {
                sum += head1->data;
                head1 = head1->next;
            }

            if (head2 != NULL) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        // Reverse result to restore correct order
        Node* result = reverse(dummy->next);

        // Remove leading zeros
        while (result != NULL && result->data == 0 && result->next != NULL) {
            result = result->next;
        }

        return result;
    }

private:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
