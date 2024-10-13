class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def deleteAlt(self, head):
        if head is None:
            return  # If the list is empty, nothing to do

        current = head

        # Traverse the list and delete every alternate node
        while current is not None and current.next is not None:
            # Skip the next node by linking current node to the one after the next
            current.next = current.next.next
            # Move to the next non-deleted node
            current = current.next

# Function to print the linked list
def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()

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
        ob.deleteAlt(head)
        printList(head)
