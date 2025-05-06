from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.strip().split()
    root = Node(int(ip[0]))
    q = deque([root])

    i = 1
    while q and i < len(ip):
        curr = q.popleft()

        if ip[i] != 'N':
            curr.left = Node(int(ip[i]))
            q.append(curr.left)
        i += 1
        if i >= len(ip): break

        if ip[i] != 'N':
            curr.right = Node(int(ip[i]))
            q.append(curr.right)
        i += 1

    return root

def leftView(root):
    result = []
    if not root:
        return result

    q = deque([root])

    while q:
        level_size = len(q)
        for i in range(level_size):
            node = q.popleft()
            if i == 0:
                result.append(node.data)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

    return result

# Example usage
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = buildTree(s)
        result = leftView(root)
        print(' '.join(map(str, result)))
        print("~")

