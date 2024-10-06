class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverse(self, head):
        if not head or head.next == head:
            return head  # If list is empty or has only one node
        
        prev = None
        curr = head
        
        while True:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            if curr == head:
                break
        
        head.next = prev  # Fix the new head
        return prev

    def deleteNode(self, head, key):
        if not head:
            return None  # If the list is empty
        
        # If the node to be deleted is the only node
        if head.data == key and head.next == head:
            return None
        
        last = head
        # If the node to be deleted is head
        if head.data == key:
            while last.next != head:
                last = last.next
            last.next = head.next
            head = last.next
            return head
        
        # Otherwise, traverse to find the node to delete
        while last.next != head and last.next.data != key:
            last = last.next
        
        if last.next.data == key:
            last.next = last.next.next
        
        return head

# Helper function to print the list
def printList(head):
    if not head:
        print("empty")
        return
    
    temp = head
    while True:
        print(temp.data, end=" ")
        temp = temp.next
        if temp == head:
            break
    print()

# Driver code
if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        arr = list(map(int, input().split()))
        key = int(input())
        
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        tail.next = head  # Make the list circular
        
        solution = Solution()
        current = solution.deleteNode(head, key)
        rev = solution.reverse(current)
        printList(rev)
