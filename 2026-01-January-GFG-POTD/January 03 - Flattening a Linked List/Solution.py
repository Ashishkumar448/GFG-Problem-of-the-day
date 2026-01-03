# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None
#         self.bottom = None

class Solution:
    # Merge two sorted linked lists using bottom pointer
    def merge(self, a, b):
        if not a:
            return b
        if not b:
            return a

        if a.data <= b.data:
            result = a
            result.bottom = self.merge(a.bottom, b)
        else:
            result = b
            result.bottom = self.merge(a, b.bottom)

        result.next = None  # ignore next pointer
        return result

    # Flatten the linked list
    def flatten(self, root):
        if not root or not root.next:
            return root

        # Recursively flatten the list to the right
        root.next = self.flatten(root.next)

        # Merge current list with flattened list
        root = self.merge(root, root.next)

        return root
