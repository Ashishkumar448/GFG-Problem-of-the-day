class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

class Solution:
    def swapKth(self, head: Node, k: int) -> Node:
        if not head:
            return head

        # Step 1: Count nodes
        n = 0
        temp = head
        while temp:
            n += 1
            temp = temp.next

        # Step 2: If k is invalid
        if k > n:
            return head

        # Step 3: If same node from both sides
        if 2 * k - 1 == n:
            return head

        # Step 4: Find kth from start
        xPrev, x = None, head
        for _ in range(1, k):
            xPrev = x
            x = x.next

        # Find kth from end => (n-k+1)th from start
        yPrev, y = None, head
        for _ in range(1, n - k + 1):
            yPrev = y
            y = y.next

        # Step 5: Swap previous pointers
        if xPrev:
            xPrev.next = y
        if yPrev:
            yPrev.next = x

        # Step 6: Swap next pointers
        tempNext = x.next
        x.next = y.next
        y.next = tempNext

        # Step 7: Update head if needed
        if k == 1:
            head = y
        elif k == n:
            head = x

        return head
