class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def countLoopLength(self, node):
        temp = node
        length = 1
        
        while temp.next != node:
            length += 1
            temp = temp.next
            
        return length

    def countNodesinLoop(self, head):
        slow = head
        fast = head
        
        # Step 1: Detect the loop using the Tortoise and Hare method
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            
            # If slow and fast meet, there's a loop
            if slow == fast:
                # Step 2: Find the loop length
                return self.countLoopLength(slow)
        
        # No loop found
        return 0

# Driver Code
if __name__ == "__main__":
    def makeLoop(head, tail, x):
        if x == 0:
            return

        curr = head
        for _ in range(1, x):
            curr = curr.next
        
        tail.next = curr

    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        
        makeLoop(head, tail, k)
        ob = Solution()
        print(ob.countNodesinLoop(head))
