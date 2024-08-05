from collections import deque, OrderedDict

# Tree Node
class Node:
    def __init__(self, key):
        self.data = key
        self.hd = float('inf')
        self.left = None
        self.right = None

# Function to build the tree from the given input string
def buildTree(s):
    if len(s) == 0 or s[0] == 'N':
        return None

    ip = s.split()
    
    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    queue = deque([root])

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        currNode = queue.popleft()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))
            # Push it to the queue
            queue.append(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break

        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))
            # Push it to the queue
            queue.append(currNode.right)
        i += 1

    return root

# Function to return a list containing the bottom view of the given tree
def bottomView(root):
    result = []
    if root is None:
        return result

    # Dictionary to store the mapping of horizontal distance to the node's value
    hd_map = OrderedDict()
    # Queue to store nodes for level order traversal
    queue = deque()

    # Set horizontal distance of root as 0
    root.hd = 0
    queue.append(root)

    # Perform level order traversal
    while queue:
        temp = queue.popleft()

        # Get the horizontal distance of the current node
        hd = temp.hd

        # Update the map with the node's value at this horizontal distance
        hd_map[hd] = temp.data

        # If there is a left child, set its horizontal distance and add it to the queue
        if temp.left:
            temp.left.hd = hd - 1
            queue.append(temp.left)

        # If there is a right child, set its horizontal distance and add it to the queue
        if temp.right:
            temp.right.hd = hd + 1
            queue.append(temp.right)

    # Add the values from the map to the result list
    for value in hd_map.values():
        result.append(value)

    return result

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = buildTree(s)
        res = bottomView(root)
        print(" ".join(map(str, res)))
