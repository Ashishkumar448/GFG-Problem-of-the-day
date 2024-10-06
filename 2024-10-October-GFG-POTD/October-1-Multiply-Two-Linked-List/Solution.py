# Definition for singly-linked list.
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def multiplyTwoLists(self, first, second):
        MOD = 1000000007
        num1 = 0
        num2 = 0

        # Convert first linked list into a number
        while first:
            num1 = (num1 * 10 + first.data) % MOD
            first = first.next

        # Convert second linked list into a number
        while second:
            num2 = (num2 * 10 + second.data) % MOD
            second = second.next

        # Return the product of both numbers modulo 10^9 + 7
        return (num1 * num2) % MOD

# Helper functions for creating and printing linked lists
def push(head_ref, new_data):
    new_node = Node(new_data)
    new_node.next = head_ref
    return new_node

def reverse(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def printList(Node):
    while Node:
        print(Node.data, end=" ")
        Node = Node.next
    print()

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        first = None
        second = None

        arr = list(map(int, input().split()))
        for num in arr:
            first = push(first, num)

        brr = list(map(int, input().split()))
        for num in brr:
            second = push(second, num)

        first = reverse(first)
        second = reverse(second)

        ob = Solution()
        res = ob.multiplyTwoLists(first, second)
        print(res)
