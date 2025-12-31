# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None

class Solution:
    def isPalindrome(self, head):
        # Edge cases
        if head is None or head.next is None:
            return True

        # Step 1: Find middle
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse second half
        second_half = self.reverseList(slow)
        first_half = head

        # Step 3: Compare
        while second_half:
            if first_half.data != second_half.data:
                return False
            first_half = first_half.next
            second_half = second_half.next

        return True

    def reverseList(self, head):
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev
