class Solution {
    // Function to rotate a linked list.
    public Node rotate(Node head, int k) {
        // If the list is empty, has only one node, or no rotation is needed
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        
        // Compute the length of the linked list
        Node current = head;
        int length = 1;
        while (current.next != null) {
            current = current.next;
            length++;
        }
        
        // Adjust k if it is greater than or equal to the length
        k = k % length;
        if (k == 0) return head; // No need to rotate if k is 0 after modulus operation
        
        // Traverse to the node just before the (k+1)th node
        current.next = head; // Connect the last node to the head to make it circular
        Node newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail.next;
        }
        
        // The new head will be the next node after the new tail
        Node newHead = newTail.next;
        
        // Break the circular list to make the rotated list
        newTail.next = null;
        
        return newHead;
    }
}
