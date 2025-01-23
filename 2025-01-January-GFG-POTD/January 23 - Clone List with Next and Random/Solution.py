class Node:
    def __init__(self, data, next=None, random=None):
        self.data = data
        self.next = next
        self.random = random

class Solution:
    def cloneLinkedList(self, head):
        if not head:
            return None

        # Step 1: Clone nodes and place them next to original nodes
        current = head
        while current:
            cloned_node = Node(current.data, current.next)
            current.next = cloned_node
            current = cloned_node.next

        # Step 2: Assign random pointers for cloned nodes
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next

        # Step 3: Separate the original and cloned lists
        original = head
        clone_head = head.next
        clone_current = clone_head

        while original:
            original.next = original.next.next
            if clone_current.next:
                clone_current.next = clone_current.next.next
            original = original.next
            clone_current = clone_current.next

        return clone_head
