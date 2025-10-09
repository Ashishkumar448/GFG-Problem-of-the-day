# Definition for a binary tree node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def postOrder(self, root):
        result = []
        self._postOrderHelper(root, result)
        return result

    def _postOrderHelper(self, node, result):
        if node is None:
            return
        
        # 1️⃣ Visit left subtree
        self._postOrderHelper(node.left, result)
        # 2️⃣ Visit right subtree
        self._postOrderHelper(node.right, result)
        # 3️⃣ Visit node itself
        result.append(node.data)
