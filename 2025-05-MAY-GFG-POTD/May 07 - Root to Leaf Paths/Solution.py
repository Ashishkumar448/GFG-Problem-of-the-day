from collections import deque
from typing import List

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(s: str) -> Node:
    if not s or s[0] == 'N':
        return None

    ip = s.strip().split()
    root = Node(int(ip[0]))
    q = deque([root])
    i = 1

    while q and i < len(ip):
        currNode = q.popleft()
        if ip[i] != 'N':
            currNode.left = Node(int(ip[i]))
            q.append(currNode.left)
        i += 1
        if i >= len(ip):
            break
        if ip[i] != 'N':
            currNode.right = Node(int(ip[i]))
            q.append(currNode.right)
        i += 1

    return root

def dfs(node: Node, currentPath: List[int], result: List[List[int]]):
    if node is None:
        return

    currentPath.append(node.data)

    if node.left is None and node.right is None:
        result.append(currentPath[:])
    else:
        dfs(node.left, currentPath, result)
        dfs(node.right, currentPath, result)

    currentPath.pop()

def Paths(root: Node) -> List[List[int]]:
    result = []
    dfs(root, [], result)
    return result

# Main
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = buildTree(s)
        res = Paths(root)
        for path in res:
            print(" ".join(map(str, path)))
        print("~")
