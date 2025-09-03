class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Solution:
    def reverse(self, head):
        if not head or not head.next:
            return head  # base case

        curr = head
        temp = None

        # Traverse and swap prev & next
        while curr:
            temp = curr.prev
            curr.prev = curr.next
            curr.next = temp
            curr = curr.prev  # move forward (which is prev now)

        # Adjust head to new head
        if temp:
            head = temp.prev

        return head
