class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None


class Solution:
    def findPreSuc(self, root, key):
        pre = None
        suc = None
        
        curr = root
        
        while curr:
            if curr.data < key:
                pre = curr          # possible predecessor
                curr = curr.right
            elif curr.data > key:
                suc = curr          # possible successor
                curr = curr.left
            else:
                # predecessor = max in left subtree
                if curr.left:
                    temp = curr.left
                    while temp.right:
                        temp = temp.right
                    pre = temp
                
                # successor = min in right subtree
                if curr.right:
                    temp = curr.right
                    while temp.left:
                        temp = temp.left
                    suc = temp
                break
        
        return [pre, suc]
