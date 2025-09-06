class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

class Solution:
    def lengthOfLoop(self, head):
        if not head:
            return 0

        slow, fast = head, head

        # Step 1: Detect loop
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                # Loop found, count its length
                return self.countLoopLength(slow)

        # No loop
        return 0

    def countLoopLength(self, meetingPoint):
        count = 1
        current = meetingPoint.next

        while current != meetingPoint:
            count += 1
            current = current.next

        return count
