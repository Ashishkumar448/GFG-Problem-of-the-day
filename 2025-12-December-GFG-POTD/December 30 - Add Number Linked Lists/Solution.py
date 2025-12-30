# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None

class Solution:
    # Function to add two numbers represented by linked lists.
    def addTwoLists(self, head1, head2):

        # Reverse both lists
        head1 = self.reverse(head1)
        head2 = self.reverse(head2)

        carry = 0
        dummy = Node(0)
        curr = dummy

        # Add digits
        while head1 or head2 or carry:
            total = carry

            if head1:
                total += head1.data
                head1 = head1.next

            if head2:
                total += head2.data
                head2 = head2.next

            carry = total // 10
            curr.next = Node(total % 10)
            curr = curr.next

        # Reverse result to restore correct order
        result = self.reverse(dummy.next)

        # Remove leading zeros
        while result and result.data == 0 and result.next:
            result = result.next

        return result

    # Helper function to reverse a linked list
    def reverse(self, head):
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev
