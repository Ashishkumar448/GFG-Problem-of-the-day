class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def findSpiral(self, root):
        result = []
        if not root:
            return result

        s1 = [root]  # Right to left
        s2 = []      # Left to right

        while s1 or s2:
            while s1:
                curr = s1.pop()
                result.append(curr.data)
                if curr.right:
                    s2.append(curr.right)
                if curr.left:
                    s2.append(curr.left)
            
            while s2:
                curr = s2.pop()
                result.append(curr.data)
                if curr.left:
                    s1.append(curr.left)
                if curr.right:
                    s1.append(curr.right)

        return result
