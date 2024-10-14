class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    # Function to count nodes of a linked list.
    def getCount(self, head):
        count = 0
        current = head
        # Traverse the linked list until the end
        while current:
            count += 1
            current = current.next  # Move to the next node
        return count

if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        arr = list(map(int, input().split()))
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        
        ob = Solution()
        print(ob.getCount(head))
