/*
class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}
*/

class Solution {
    // Function to add two numbers represented by linked lists.
    public Node addTwoLists(Node head1, Node head2) {

        // Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node dummy = new Node(0);
        Node curr = dummy;

        // Add digits
        while (head1 != null || head2 != null || carry != 0) {
            int sum = carry;

            if (head1 != null) {
                sum += head1.data;
                head1 = head1.next;
            }

            if (head2 != null) {
                sum += head2.data;
                head2 = head2.next;
            }

            carry = sum / 10;
            curr.next = new Node(sum % 10);
            curr = curr.next;
        }

        // Reverse result to restore correct order
        Node result = reverse(dummy.next);

        // Remove leading zeros
        while (result != null && result.data == 0 && result.next != null) {
            result = result.next;
        }

        return result;
    }

    // Helper function to reverse a linked list
    private Node reverse(Node head) {
        Node prev = null, curr = head;

        while (curr != null) {
            Node nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
}
