class Node:
    def __init__(self, key):
        self.data = key
        self.next = None

class Solution:
    def mergeSort(self, head):
        if head is None or head.next is None:
            return head

        # Step 1: Find middle
        middle = self.getMiddle(head)
        next_of_middle = middle.next

        # Split
        middle.next = None

        # Recursively sort halves
        left = self.mergeSort(head)
        right = self.mergeSort(next_of_middle)

        # Merge sorted halves
        return self.sortedMerge(left, right)

    # Merge two sorted lists
    def sortedMerge(self, a, b):
        if not a:
            return b
        if not b:
            return a

        if a.data <= b.data:
            result = a
            result.next = self.sortedMerge(a.next, b)
        else:
            result = b
            result.next = self.sortedMerge(a, b.next)
        return result

    # Find middle of list
    def getMiddle(self, head):
        if head is None:
            return head

        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
