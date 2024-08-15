class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    # Function to reverse the linked list
    def reverseList(self, head):
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev
    
    # Function to add one to the linked list
    def addOne(self, head):
        # Reverse the linked list
        head = self.reverseList(head)
        
        current = head
        carry = 1  # Initialize carry to 1 since we are adding 1
        
        # Traverse the list and add the carry
        while current:
            sum = current.data + carry
            current.data = sum % 10  # Update the node's value
            carry = sum // 10  # Calculate the new carry
            prev = current
            current = current.next
        
        # If there is still a carry after processing all nodes
        if carry > 0:
            prev.next = Node(carry)
        
        # Reverse the linked list again to restore the original order
        return self.reverseList(head)

def printList(node):
    while node:
        print(node.data, end="")
        node = node.next
    print()

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        
        obj = Solution()
        head = obj.addOne(head)
        printList(head)
