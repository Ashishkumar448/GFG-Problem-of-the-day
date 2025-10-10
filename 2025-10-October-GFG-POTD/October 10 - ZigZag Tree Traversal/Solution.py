# Definition for a binary tree node.
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def zigZagTraversal(self, root):
        if not root:
            return []
        
        from collections import deque
        result = []
        queue = deque([root])
        left_to_right = True
        
        while queue:
            size = len(queue)
            level = []
            
            for _ in range(size):
                node = queue.popleft()
                level.append(node.data)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            if not left_to_right:
                level.reverse()
            
            result.extend(level)
            left_to_right = not left_to_right
        
        return result
