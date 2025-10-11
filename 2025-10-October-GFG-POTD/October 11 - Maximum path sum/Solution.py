class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.res = float('-inf')

    def findMaxSum(self, root):
        self.maxPathDown(root)
        return self.res

    def maxPathDown(self, node):
        if node is None:
            return 0

        # Compute maximum path sum on left and right subtrees
        left = max(0, self.maxPathDown(node.left))
        right = max(0, self.maxPathDown(node.right))

        # Update global result (max path sum through the current node)
        self.res = max(self.res, node.data + left + right)

        # Return max path sum going upward (only one branch)
        return node.data + max(left, right)
