# Definition for a binary tree node.
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def nodeSum(self, root, l, r):
        if root is None:
            return 0
        
        # If root's value is smaller than l, skip left subtree
        if root.data < l:
            return self.nodeSum(root.right, l, r)
        
        # If root's value is greater than r, skip right subtree
        if root.data > r:
            return self.nodeSum(root.left, l, r)
        
        # Root's value is within [l, r]
        return root.data + self.nodeSum(root.left, l, r) + self.nodeSum(root.right, l, r)
