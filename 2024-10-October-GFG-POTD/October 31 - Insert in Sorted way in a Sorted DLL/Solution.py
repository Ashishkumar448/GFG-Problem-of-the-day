class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class Solution:
    def sortedInsert(self, head, x):
        newNode = Node(x)

        # Case 1: List is empty
        if head is None:
            return newNode

        # Case 2: Insert at the beginning if x is less than head's data
        if x <= head.data:
            newNode.next = head
            head.prev = newNode
            return newNode  # New head of the list

        # Case 3: Traverse and find the appropriate position to insert
        current = head
        while current.next is not None and current.next.data < x:
            current = current.next

        # Case 4: Insert after 'current' node
        newNode.next = current.next
        newNode.prev = current
        if current.next is not None:
            current.next.prev = newNode
        current.next = newNode

        return head  # Head remains the same

def printList(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        values = list(map(int, input().strip().split()))
        head = None
        tail = None
        for value in values:
            if head is None:
                head = Node(value)
                tail = head
            else:
                tail.next = Node(value)
                tail.next.prev = tail
                tail = tail.next

        valueToInsert = int(input())
        solution = Solution()
        head = solution.sortedInsert(head, valueToInsert)
        printList(head)
        print("~")
