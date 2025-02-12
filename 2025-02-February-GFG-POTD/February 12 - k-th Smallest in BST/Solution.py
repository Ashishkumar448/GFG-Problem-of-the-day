class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def kthSmallest(self, root, k):
        stack = []
        current = root
        count = 0

        while current is not None or stack:
            # Traverse left subtree
            while current is not None:
                stack.append(current)
                current = current.left
            
            # Process the node
            current = stack.pop()
            count += 1

            # If count == k, return the node's data
            if count == k:
                return current.data

            # Move to right subtree
            current = current.right

        return -1  # If k is out of bounds

# Utility function to build BST from level order input
def buildTree(arr):
    if not arr or arr[0] == "N":
        return None

    root = Node(int(arr[0]))
    queue = [root]
    i = 1

    while queue and i < len(arr):
        current = queue.pop(0)

        if arr[i] != "N":
            current.left = Node(int(arr[i]))
            queue.append(current.left)
        i += 1

        if i >= len(arr):
            break

        if arr[i] != "N":
            current.right = Node(int(arr[i]))
            queue.append(current.right)
        i += 1

    return root

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = input().split()
        root = buildTree(arr)
        k = int(input())
        sol = Solution()
        print(sol.kthSmallest(root, k))
