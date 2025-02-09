class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def findMaxSum(self, root):
        self.res = float('-inf')
        self.findMaxUtil(root)
        return self.res

    def findMaxUtil(self, node):
        if not node:
            return 0

        # Compute the maximum path sum of left and right subtrees
        left = max(0, self.findMaxUtil(node.left))
        right = max(0, self.findMaxUtil(node.right))

        # Update the global maximum path sum
        self.res = max(self.res, left + right + node.data)

        # Return the max path sum including the current node and one of its children
        return node.data + max(left, right)

# Driver Code
if __name__ == "__main__":
    root = Node(10)
    root.left = Node(2)
    root.right = Node(10)
    root.left.left = Node(20)
    root.left.right = Node(1)
    root.right.right = Node(-25)
    root.right.right.left = Node(3)
    root.right.right.right = Node(4)

    obj = Solution()
    print(obj.findMaxSum(root))  # Output: 42
