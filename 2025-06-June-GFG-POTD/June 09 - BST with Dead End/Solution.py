class Solution:
    def isDeadEnd(self, root):
        return self.helper(root, 1, float('inf'))

    def helper(self, node, min_val, max_val):
        if node is None:
            return False

        if min_val == max_val:
            return True

        return (self.helper(node.left, min_val, node.data - 1) or
                self.helper(node.right, node.data + 1, max_val))
