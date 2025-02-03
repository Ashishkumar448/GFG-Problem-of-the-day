import sys
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    # Function to find the height of a binary tree.
    def height(self, node):
        return -1 if node is None else 1 + max(self.height(node.left), self.height(node.right))

# Function to build tree from a string input
def buildTree(s):
    if len(s) == 0 or s[0] == "N":
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    queue = deque([root])
    
    i = 1
    while queue and i < len(ip):
        currNode = queue.popleft()

        currVal = ip[i]
        if currVal != "N":
            currNode.left = Node(int(currVal))
            queue.append(currNode.left)

        i += 1
        if i >= len(ip):
            break

        currVal = ip[i]
        if currVal != "N":
            currNode.right = Node(int(currVal))
            queue.append(currNode.right)

        i += 1

    return root

if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        treeString = sys.stdin.readline().strip()
        root = buildTree(treeString)
        ob = Solution()
        print(ob.height(root))
        print("~")
