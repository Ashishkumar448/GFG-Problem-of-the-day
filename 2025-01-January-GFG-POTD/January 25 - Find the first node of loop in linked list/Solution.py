class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

class Solution:
    def findFirstNode(self, head):
        if head is None or head.next is None:
            return None

        slow, fast = head, head

        # Step 1: Detect loop using Floyd's Cycle Detection Algorithm
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                # Step 2: Find the start of the loop
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow  # The first node in the loop

        # No loop found
        return None

def makeLoop(head, tail, x):
    if x == 0:
        return

    curr = head
    for _ in range(1, x):
        curr = curr.next

    tail.next = curr

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())

        head = Node(arr[0])
        tail = head
        for val in arr[1:]:
            tail.next = Node(val)
            tail = tail.next

        makeLoop(head, tail, k)

        obj = Solution()
        ans = obj.findFirstNode(head)
        print(ans.data if ans else -1)
