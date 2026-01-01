class Node:
    def __init__(self, d):
        self.data = d
        self.next = None

class Solution:
    def intersectPoint(self, head1, head2):
        p1 = head1
        p2 = head2

        # Traverse until both pointers meet
        while p1 != p2:
            p1 = head2 if p1 is None else p1.next
            p2 = head1 if p2 is None else p2.next

        # p1 (or p2) is the intersection node
        return p1
