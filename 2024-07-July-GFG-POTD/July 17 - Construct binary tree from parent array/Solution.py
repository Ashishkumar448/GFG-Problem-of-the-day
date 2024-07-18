class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def height(root):
    if root is None:
        return 0
    else:
        lheight = height(root.left)
        rheight = height(root.right)
        if lheight > rheight:
            return lheight + 1
        else:
            return rheight + 1

def printLevelOrder(root):
    h = height(root)
    for i in range(1, h + 1):
        queue = []
        queue.append(root)
        while queue:
            levelSize = len(queue)
            levelValues = []
            for _ in range(levelSize):
                current = queue.pop(0)
                levelValues.append(current.data)
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            levelValues.sort()
            print(*levelValues, end=" ")
        print()

def createTree(parent, n):
    nodes = [None] * n
    for i in range(n):
        nodes[i] = Node