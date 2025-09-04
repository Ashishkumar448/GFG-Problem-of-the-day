class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        if not head or k == 1:
            return head
        dummy = Node(0)
        dummy.next = head
        pre = dummy
        end = dummy

        while True:
            count = 0
            while end and count < k:
                end = end.next
                count += 1
            if not end:
                break
            start = pre.next
            nxt = end.next
            end.next = None  # Temporarily break
            pre.next = self.reverse(start)
            start.next = nxt
            pre = start
            end = pre
        if pre.next:
            pre.next = self.reverse(pre.next)
        return dummy.next

    def reverse(self, head):
        prev = None
        curr = head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
