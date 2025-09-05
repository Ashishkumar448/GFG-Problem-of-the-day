/*
class Node {
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}*/

class Solution {
     public Node segregate(Node head) {
        if (head == null || head.next == null) return head;

        // Dummy nodes for 0s, 1s, 2s
        Node zeroD = new Node(-1), oneD = new Node(-1), twoD = new Node(-1);
        Node zero = zeroD, one = oneD, two = twoD;

        Node curr = head;

        // Partition into three lists
        while (curr != null) {
            if (curr.data == 0) {
                zero.next = curr;
                zero = zero.next;
            } else if (curr.data == 1) {
                one.next = curr;
                one = one.next;
            } else {
                two.next = curr;
                two = two.next;
            }
            curr = curr.next;
        }

        // Connect three lists
        zero.next = (oneD.next != null) ? oneD.next : twoD.next;
        one.next = twoD.next;
        two.next = null;  // end of final list

        // Head of new list
        return zeroD.next;
    }
}
