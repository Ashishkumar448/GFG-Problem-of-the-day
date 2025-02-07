class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def boundaryTraversal(self, root):
        if not root:
            return []

        result = []

        # Step 1: Add Root (Only if it's not a leaf)
        if not self.isLeaf(root):
            result.append(root.data)

        # Step 2: Left Boundary (excluding leaf nodes)
        self.addLeftBoundary(root.left, result)

        # Step 3: Leaf Nodes
        self.addLeaves(root, result)

        # Step 4: Right Boundary (excluding leaf nodes, reverse order)
        rightBoundary = []
        self.addRightBoundary(root.right, rightBoundary)
        result.extend(reversed(rightBoundary))

        return result

    # Function to check if a node is a leaf node
    def isLeaf(self, node):
        return node.left is None and node.right is None

    # Function to add left boundary nodes (excluding leaf nodes)
    def addLeftBoundary(self, node, result):
        while node:
            if not self.isLeaf(node):
                result.append(node.data)
            node = node.left if node.left else node.right

    # Function to add all leaf nodes in left-to-right order
    def addLeaves(self, node, result):
        if node is None:
            return
        if self.isLeaf(node):
            result.append(node.data)
            return
        self.addLeaves(node.left, result)
        self.addLeaves(node.right, result)

    # Function to add right boundary nodes (excluding leaf nodes)
    def addRightBoundary(self, node, result):
        while node:
            if not self.isLeaf(node):
                result.append(node.data)
            node = node.right if node.right else node.left

# Function to build tree from input string
def buildTree(s):
    if not s or s == "N":
        return None

    values = s.split()
    root = Node(int(values[0]))
    queue = [root]
    i = 1

    while queue and i < len(values):
        currNode = queue.pop(0)

        if values[i] != "N":
            currNode.left = Node(int(values[i]))
            queue.append(currNode.left)
        i += 1
        if i >= len(values):
            break

        if values[i] != "N":
            currNode.right = Node(int(values[i]))
            queue.append(currNode.right)
        i += 1

    return root

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        root = buildTree(s)
        obj = Solution()
        res = obj.boundaryTraversal(root)
        print(" ".join(map(str, res)))
