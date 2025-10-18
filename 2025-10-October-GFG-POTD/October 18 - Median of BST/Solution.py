# Definition for a binary tree node.
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    # Function to count total nodes in BST
    def countNodes(self, root):
        if root is None:
            return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    # Helper for inorder traversal to find median
    def findMedianUtil(self, root, targetIndex, count):
        if root is None:
            return -1

        # Search left subtree
        left = self.findMedianUtil(root.left, targetIndex, count)
        if left != -1:
            return left

        # Visit current node
        count[0] += 1
        if count[0] == targetIndex:
            return root.data

        # Search right subtree
        return self.findMedianUtil(root.right, targetIndex, count)

    def findMedian(self, root):
        if root is None:
            return 0

        # Step 1: count total nodes
        n = self.countNodes(root)

        # Step 2: find target index
        targetIndex = (n // 2) if (n % 2 == 0) else ((n + 1) // 2)

        # Step 3: second inorder traversal to get target element
        count = [0]  # acts as mutable counter
        return self.findMedianUtil(root, targetIndex, count)
