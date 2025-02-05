import sys
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    # Function to convert a binary tree into its mirror tree.
    def mirror(self, node):
        if node is None:
            return

        # Swap the left and right child nodes
        node.left, node.right = node.right, node.left

        # Recursively call for left and right subtrees
        self.mirror(node.left)
        self.mirror(node.right)

# Function to build a tree from level order input
def buildTree(s):
    if not s or s[0] == "N":
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    queue = deque([root])

    i = 1
    while queue and i < len(ip):
        curr = queue.popleft()

        if ip[i] != "N":
            curr.left = Node(int(ip[i]))
            queue.append(curr.left)
        i += 1

        if i >= len(ip):
            break

        if ip[i] != "N":
            curr.right = Node(int(ip[i]))
            queue.append(curr.right)
        i += 1

    return root

# Function to print level-order traversal of the tree
def levelOrder(root):
    if root is None:
        print("N")
        return

    queue = deque([root])
    result = []

    while queue:
        curr = queue.popleft()

        if curr is None:
            result.append("N")
            continue

        result.append(str(curr.data))
        queue.append(curr.left)
        queue.append(curr.right)

    print(" ".join(result))

if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())

    for _ in range(t):
        s = sys.stdin.readline().strip()
        root = buildTree(s)

        obj = Solution()
        obj.mirror(root)
        levelOrder(root)
        print("~")
