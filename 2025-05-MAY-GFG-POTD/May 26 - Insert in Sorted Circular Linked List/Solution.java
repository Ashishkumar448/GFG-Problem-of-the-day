/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
} */

class Solution {
    public Node sortedInsert(Node head, int data) {
        Node newNode = new Node(data);

        // Case 1: Empty list
        if (head == null) {
            newNode.next = newNode;
            return newNode;
        }

        Node current = head;

        // Case 2: Insert before head (smallest data) or in the correct position
        while (true) {
            // Case: Insert in between current and next (normal case)
            if (current.data <= data && data <= current.next.data) {
                break;
            }

            // Case: At the point of circular jump (max -> min)
            if (current.data > current.next.data) {
                // Data is either new max or new min
                if (data >= current.data || data <= current.next.data) {
                    break;
                }
            }

            current = current.next;

            // Full circle done, insert at end
            if (current == head) {
                break;
            }
        }

        // Insert newNode between current and current.next
        newNode.next = current.next;
        current.next = newNode;

        // If inserted before head (new smallest element), return newNode as new head
        return head.data <= data ? head : newNode;
    }
}
