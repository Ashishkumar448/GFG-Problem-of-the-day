class Info:
    def __init__(self, min_val, max_val, size, is_bst):
        self.min = min_val
        self.max = max_val
        self.size = size
        self.isBST = is_bst


class Solution:
    def largestBst(self, root):
        self.maxSize = 0
        self.solve(root)
        return self.maxSize

    def solve(self, root):
        # Base case
        if not root:
            return Info(float('inf'), float('-inf'), 0, True)

        left = self.solve(root.left)
        right = self.solve(root.right)

        # Check BST condition
        if left.isBST and right.isBST and root.data > left.max and root.data < right.min:
            size = left.size + right.size + 1
            self.maxSize = max(self.maxSize, size)

            min_val = min(root.data, left.min)
            max_val = max(root.data, right.max)

            return Info(min_val, max_val, size, True)

        # Not BST
        return Info(float('-inf'), float('inf'), max(left.size, right.size), False)
      
