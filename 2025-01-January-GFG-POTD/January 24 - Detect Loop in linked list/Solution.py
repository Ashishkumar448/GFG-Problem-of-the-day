class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def make_loop(head, tail, x):
    if x == 0:
        return

    curr = head
    for _ in range(1, x):
        curr = curr.next

    tail.next = curr

class Solution:
    # Function to check if the linked list has a loop.
    def detectLoop(self, head):
        if not head or not head.next:
            return False

        slow = head  # Slow pointer
        fast = head  # Fast pointer

        while fast and fast.next:
            slow = slow.next          # Move slow pointer one step
            fast = fast.next.next     # Move fast pointer two steps

            # If slow and fast pointers meet, a loop is detected
            if slow == fast:
                return True

        return False  # No loop detected

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        pos = int(input().strip())

        head = None
        if arr:
            head = Node(arr[0])
            tail = head
            for val in arr[1:]:
                tail.next = Node(val)
                tail = tail.next

            make_loop(head, tail, pos)

        sol = Solution()
        if sol.detectLoop(head):
            print("true")
        else:
            print("false")

        print("~")
