class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def RemoveHalfNodes(self, root):
        if root is None:
            return None
        
        root.left = self.RemoveHalfNodes(root.left)
        root.right = self.RemoveHalfNodes(root.right)
        
        if root.left is None and root.right is not None:
            return root.right
        
        if root.left is not None and root.right is None:
            return root.left
        
        return root

# Helper function to print InOrder traversal
def printInOrder(node):
    if node is None:
        return
    printInOrder(node.left)
    print(node.data, end=' ')
    printInOrder(node.right)

# Example usage
root = Node(5)
root.left = Node(7)
root.right = Node(8)
root.left.left = Node(2)

solution = Solution()
new_root = solution.RemoveHalfNodes(root)
printInOrder(new_root)  # Output: 2 5 8
