class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    # Function to return a list containing the inorder traversal of the tree.
    def inOrder(self, root):
        result = []
        self.inorderHelper(root, result)
        return result

    # Helper function for recursion
    def inorderHelper(self, node, result):
        if node is None:
            return
        self.inorderHelper(node.left, result)  # Visit left subtree
        result.append(node.data)               # Visit node
        self.inorderHelper(node.right, result) # Visit right subtree

# Function to build tree from input
def buildTree(s):
    if len(s) == 0 or s[0] == "N":
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    queue = [root]

    i = 1
    while queue and i < len(ip):
        currNode = queue.pop(0)

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

# Driver code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        root = buildTree(s)
        sol = Solution()
        res = sol.inOrder(root)
        print(" ".join(map(str, res)))
