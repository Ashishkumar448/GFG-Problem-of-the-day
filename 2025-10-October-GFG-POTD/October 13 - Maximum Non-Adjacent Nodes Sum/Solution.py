class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    class Pair:
        def __init__(self, include, exclude):
            self.include = include
            self.exclude = exclude

    def getMaxSum(self, root):
        result = self.solve(root)
        return max(result.include, result.exclude)

    def solve(self, node):
        if node is None:
            return self.Pair(0, 0)

        left = self.solve(node.left)
        right = self.solve(node.right)

        include = node.data + left.exclude + right.exclude
        exclude = max(left.include, left.exclude) + max(right.include, right.exclude)

        return self.Pair(include, exclude)


# Example usage:
# root = Node(1)
# root.left = Node(2)
# root.right = Node(3)
# root.left.left = Node(4)
# root.right.left = Node(5)
# root.right.right = Node(6)
# print(Solution().getMaxSum(root))  # Output: 16
