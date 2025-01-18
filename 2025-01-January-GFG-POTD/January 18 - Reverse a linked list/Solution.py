class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()

def reverseList(head):
    prev = None
    current = head

    while current:
        next_node = current.next  # Store the next node
        current.next = prev       # Reverse the link
        prev = current            # Move prev one step forward
        current = next_node       # Move current one step forward

    return prev  # prev will be the new head

# Driver code
t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))
    head = Node(arr[0])
    tail = head

    for value in arr[1:]:
        tail.next = Node(value)
        tail = tail.next

    head = reverseList(head)
    printList(head)
    print("~")
