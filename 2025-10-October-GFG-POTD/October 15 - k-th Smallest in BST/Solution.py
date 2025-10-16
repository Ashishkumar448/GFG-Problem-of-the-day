"""
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

class Solution:
    def __init__(self):
        self.count = 0
        self.result = -1

    def kthSmallest(self, root, k):
        self._inorder(root, k)
        return self.result

    def _inorder(self, root, k):
        if not root:
            return

        self._inorder(root.left, k)

        self.count += 1
        if self.count == k:
            self.result = root.data
            return

        self._inorder(root.right, k)
