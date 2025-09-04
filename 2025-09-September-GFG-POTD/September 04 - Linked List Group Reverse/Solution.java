/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node reverseKGroup(Node head, int k) {
        if (head == null || k == 1) return head;
        Node dummy = new Node(0);
        dummy.next = head;

        Node pre = dummy, end = dummy;

        while (true) {
            int count = 0;
            // Move 'end' to the end of the k-group
            while (end != null && count < k) {
                end = end.next;
                count++;
            }
            if (end == null) break;

            Node start = pre.next;
            Node next = end.next;
            end.next = null; // Temporarily break

            // Reverse from start to end
            pre.next = reverse(start);

            // Connect with next part
            start.next = next;

            // Move pointers forward for next group
            pre = start;
            end = pre;
        }

        // Handle the last group if nodes remain, reverse those as a group
        if (pre.next != null) {
            pre.next = reverse(pre.next);
        }
        return dummy.next;
    }

    // Helper function to reverse entire list
    private Node reverse(Node head) {
        Node prev = null, curr = head;
        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
