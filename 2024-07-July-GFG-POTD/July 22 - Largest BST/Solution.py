class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def largestBst(self, root):
        def largestBstHelper(node):
            if node is None:
                return (0, float('-inf'), float('inf'), 0, True)

            if node.left is None and node.right is None:
                return (1, node.data, node.data, 1, True)

            leftInfo = largestBstHelper(node.left)
            rightInfo = largestBstHelper(node.right)

            size = 1 + leftInfo[0] + rightInfo[0]

            if leftInfo[4] and rightInfo[4] and node.data > leftInfo[1] and node.data < rightInfo[2]:
                minVal = min(leftInfo[2], node.data)
                maxVal = max(rightInfo[1], node.data)
                largestBSTSize = size
                isBST = True
            else:
                largestBSTSize = max(leftInfo[3], rightInfo[3])
                minVal = maxVal = node.data
                isBST = False

            return (size, maxVal, minVal, largestBSTSize, isBST)

        return largestBstHelper(root)[3]

# Helper function to create a new node
def newNode(data):
    return Node(data)

# Driver code to test the solution
if __name__ == "__main__":
    # Constructing the following tree
    #       50
    #     /    \
    #    30     60
    #   /  \   /  \
    #  5   20 45   70
    #               / \
    #              65  80
    root = newNode(50)
    root.left = newNode(30)
    root.right = newNode(60)
    root.left.left = newNode(5)
    root.left.right = newNode(20)
    root.right.left = newNode(45)
    root.right.right = newNode(70)
    root.right.right.left = newNode(65)
    root.right.right.right = newNode(80)

    solution = Solution()
    print("Size of largest BST is", solution.largestBst(root))  # Output: 5
