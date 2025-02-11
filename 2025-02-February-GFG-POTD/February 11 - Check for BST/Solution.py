import sys
from collections import deque

# Definition for a binary tree node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Utility function to check if the tree is a BST
def isBSTUtil(node, min_val, max_val):
    if node is None:
        return True

    if node.data <= min_val or node.data >= max_val:
        return False

    return isBSTUtil(node.left, min_val, node.data) and \
           isBSTUtil(node.right, node.data, max_val)

# Function to check whether a Binary Tree is BST or not
def isBST(root):
    return isBSTUtil(root, float('-inf'), float('inf'))

# Function to build a tree from input
def buildTree(ip):
    if not ip or ip[0] == "N":
        return None

    root = Node(int(ip[0]))
    queue = deque([root])
    i = 1

    while queue and i < len(ip):
        currNode = queue.popleft()

        if ip[i] != "N":
            currNode.left = Node(int(ip[i]))
            queue.append(currNode.left)
        
        i += 1
        if i >= len(ip):
            break

        if ip[i] != "N":
            currNode.right = Node(int(ip[i]))
            queue.append(currNode.right)

        i += 1

    return root

# Driver function
if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())

    for _ in range(t):
        s = sys.stdin.readline().strip()
        ip = s.split()
        root = buildTree(ip)
        
        if isBST(root):
            print("true")
        else:
            print("false")

        print("~")
