# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.left = None
#         self.right = None

class Solution:
    def getKClosest(self, root, target, k):
        inorder_list = []
        self.inorderTraversal(root, inorder_list)

        # Sort by absolute difference, then by value
        inorder_list.sort(key=lambda x: (abs(x - target), x))

        # Pick first k elements
        return inorder_list[:k]

    def inorderTraversal(self, root, lst):
        if not root:
            return
        self.inorderTraversal(root.left, lst)
        lst.append(root.data)
        self.inorderTraversal(root.right, lst)
