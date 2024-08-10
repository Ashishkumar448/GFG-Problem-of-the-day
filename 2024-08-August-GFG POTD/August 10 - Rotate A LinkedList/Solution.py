class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def rotate(self, head, k):
        # If the list is empty, has only one node, or no rotation is needed
        if not head or not head.next or k == 0:
            return head

        # Compute the length of the linked list
        current = head
        length = 1
        while current.next:
            current = current.next
            length += 1

        # Adjust k if it is greater than or equal to the length
        k = k % length
        if k == 0:
            return head  # No need to rotate if k is 0 after modulus operation

        # Traverse to the node just before the (k+1)th node
        current.next = head  # Connect the last node to the head to make it circular
        new_tail = head
        for _ in range(1, k):
            new_tail = new_tail.next

        # The new head will be the next node after the new tail
        new_head = new_tail.next

        # Break the circular list to make the rotated list
        new_tail.next = None

        return new_head

# Utility function to print a linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()

# Example usage
if __name__ == "__main__":
    head = Node(2)
    head.next = Node(4)
    head.next.next = Node(7)
    head.next.next.next = Node(8)
    head.next.next.next.next = Node(9)

    k = 3

    ob = Solution()
    head = ob.rotate(head, k)
    printList(head)
