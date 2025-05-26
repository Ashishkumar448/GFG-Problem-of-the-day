class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def sortedInsert(self, head: 'Node', data: int) -> 'Node':
        new_node = Node(data)

        # Case 1: Empty list
        if not head:
            new_node.next = new_node
            return new_node

        current = head

        while True:
            # Case: Insert in between current and current.next
            if current.data <= data <= current.next.data:
                break

            # Case: At rotation point (max -> min)
            if current.data > current.next.data:
                if data >= current.data or data <= current.next.data:
                    break

            current = current.next

            # Completed full circle
            if current == head:
                break

        new_node.next = current.next
        current.next = new_node

        # Return new head if new node is the new smallest
        return head if head.data <= data else new_node
