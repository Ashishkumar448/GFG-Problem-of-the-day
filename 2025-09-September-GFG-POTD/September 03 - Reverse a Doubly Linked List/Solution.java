/*
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
*/
class Solution {
    public Node reverse(Node head) {
        if (head == null || head.next == null) return head; // base case

        Node curr = head;
        Node temp = null;

        // Traverse the list and swap prev & next for every node
        while (curr != null) {
            // swap prev and next
            temp = curr.prev;
            curr.prev = curr.next;
            curr.next = temp;

            // move to the next node (which is curr.prev after swap)
            curr = curr.prev;
        }

        // After the loop, temp will be at the new head's prev
        if (temp != null) {
            head = temp.prev; 
        }

        return head;
    }
}
