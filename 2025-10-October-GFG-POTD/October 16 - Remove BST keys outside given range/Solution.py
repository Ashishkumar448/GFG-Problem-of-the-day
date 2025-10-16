"""
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

class Solution:
    def removekeys(self, root, l, r):
        # Base case: if tree is empty
        if not root:
            return None

        # Recur for left and right subtrees
        root.left = self.removekeys(root.left, l, r)
        root.right = self.removekeys(root.right, l, r)

        # If current node's value is smaller than l,
        # discard left subtree and current node
        if root.data < l:
            return root.right

        # If current node's value is greater than r,
        # discard right subtree and current node
        if root.data > r:
            return root.left

        # Current node is in range
        return root
