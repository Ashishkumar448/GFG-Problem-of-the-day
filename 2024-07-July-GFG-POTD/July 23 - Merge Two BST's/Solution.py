class Solution:
    def merge(self, root1, root2):
        def inorder_traversal(node, result):
            if node:
                inorder_traversal(node.left, result)
                result.append(node.data)
                inorder_traversal(node.right, result)
        
        result = []
        inorder_traversal(root1, result)
        inorder_traversal(root2, result)
        return result
