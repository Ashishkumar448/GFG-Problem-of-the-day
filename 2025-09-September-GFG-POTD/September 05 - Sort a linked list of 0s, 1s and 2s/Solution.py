class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def segregate(self, head: Node) -> Node:
        if head is None or head.next is None:
            return head

        # Dummy nodes for 0s, 1s, 2s
        zeroD = Node(-1)
        oneD = Node(-1)
        twoD = Node(-1)

        zero = zeroD
        one = oneD
        two = twoD

        curr = head

        # Partition into three lists
        while curr:
            if curr.data == 0:
                zero.next = curr
                zero = zero.next
            elif curr.data == 1:
                one.next = curr
                one = one.next
            else:
                two.next = curr
                two = two.next
            curr = curr.next

        # Connect three lists
        zero.next = oneD.next if oneD.next else twoD.next
        one.next = twoD.next
        two.next = None  # end of final list

        return zeroD.next
