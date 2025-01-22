class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverse(self, head):
        prev, curr = None, head
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        return prev

    def addTwoLists(self, l1, l2):
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        dummy = Node(0)
        tail = dummy
        carry = 0

        while l1 or l2 or carry:
            sum_val = carry
            if l1:
                sum_val += l1.data
                l1 = l1.next
            if l2:
                sum_val += l2.data
                l2 = l2.next
            carry = sum_val // 10
            tail.next = Node(sum_val % 10)
            tail = tail.next

        res = self.reverse(dummy.next)
        while res and res.data == 0 and res.next:
            res = res.next
        return res

def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        values1 = list(map(int, input().split()))
        num1 = Node(values1[0])
        tail1 = num1
        for val in values1[1:]:
            tail1.next = Node(val)
            tail1 = tail1.next

        m = int(input())
        values2 = list(map(int, input().split()))
        num2 = Node(values2[0])
        tail2 = num2
        for val in values2[1:]:
            tail2.next = Node(val)
            tail2 = tail2.next

        sol = Solution()
        result = sol.addTwoLists(num1, num2)
        printList(result)
