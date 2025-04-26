from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(s):
    if not s or s[0] == "N":
        return None

    ip = s.strip().split()
    root = Node(int(ip[0]))
    q = deque([root])

    i = 1
    while q and i < len(ip):
        curr = q.popleft()

        if ip[i] != "N":
            curr.left = Node(int(ip[i]))
            q.append(curr.left)
        i += 1

        if i >= len(ip): break

        if ip[i] != "N":
            curr.right = Node(int(ip[i]))
            q.append(curr.right)
        i += 1

    return root

def isHeap(root):
    if not root:
        return True

    q = deque([root])
    nullChildSeen = False

    while q:
        curr = q.popleft()

        if curr.left:
            if nullChildSeen or curr.left.data > curr.data:
                return False
            q.append(curr.left)
        else:
            nullChildSeen = True

        if curr.right:
            if nullChildSeen or curr.right.data > curr.data:
                return False
            q.append(curr.right)
        else:
            nullChildSeen = True

    return True

# Driver code
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s)
    print("true" if isHeap(root) else "false")
    print("~")
