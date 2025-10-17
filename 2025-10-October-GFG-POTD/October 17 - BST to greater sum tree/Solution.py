class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.sum = 0

    def transformTree(self, root):
        self.sum = 0  # Reset before starting
        self._transform(root)

    def _transform(self, root):
        if root is None:
            return

        # Traverse right subtree first (larger values)
        self._transform(root.right)

        # Process current node
        temp = root.data
        root.data = self.sum
        self.sum += temp

        # Traverse left subtree (smaller values)
        self._transform(root.left)
