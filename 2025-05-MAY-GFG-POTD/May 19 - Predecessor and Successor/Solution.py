class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def findPreSuc(self, root, key):
        pre = None
        suc = None
        curr = root

        while curr:
            if curr.data == key:
                # Predecessor: max in left subtree
                if curr.left:
                    temp = curr.left
                    while temp.right:
                        temp = temp.right
                    pre = temp

                # Successor: min in right subtree
                if curr.right:
                    temp = curr.right
                    while temp.left:
                        temp = temp.left
                    suc = temp
                break

            elif key < curr.data:
                suc = curr
                curr = curr.left
            else:
                pre = curr
                curr = curr.right

        return (pre, suc)

# Example usage:
# Build your own BST using Node class and call findPreSuc(root, key)
