from collections import deque
import sys
sys.setrecursionlimit(10**7)

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(s):
    if len(s) == 0 or s[0] == 'N':
        return None
    
    ip = s.split()
    root = Node(int(ip[0]))
    queue = deque([root])
    i = 1

    while queue and i < len(ip):
        currNode = queue.popleft()

        currVal = ip[i]
        if currVal != "N":
            currNode.left = Node(int(currVal))
            queue.append(currNode.left)
        i += 1

        if i >= len(ip):
            break
        currVal = ip[i]
        if currVal != "N":
            currNode.right = Node(int(currVal))
            queue.append(currNode.right)
        i += 1

    return root

def isBST(root, lower=float('-inf'), upper=float('inf')):
    if not root:
        return True
    if not (lower < root.data < upper):
        return False
    return isBST(root.left, lower, root.data) and isBST(root.right, root.data, upper)

def compareTrees(a, b, mismatch):
    if not a and not b:
        return True
    if not a or not b:
        return False
    if a.data != b.data:
        mismatch.append((a.data, b.data))
    return compareTrees(a.left, b.left, mismatch) and compareTrees(a.right, b.right, mismatch)

class Solution:
    def __init__(self):
        self.first = self.middle = self.last = self.prev = None

    def correctBST(self, root):
        self.inorder(root)
        if self.first and self.last:
            self.first.data, self.last.data = self.last.data, self.first.data
        elif self.first and self.middle:
            self.first.data, self.middle.data = self.middle.data, self.first.data

    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        if self.prev and root.data < self.prev.data:
            if not self.first:
                self.first, self.middle = self.prev, root
            else:
                self.last = root
        self.prev = root
        self.inorder(root.right)


t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s)
    duplicate = buildTree(s)

    sol = Solution()
    sol.correctBST(root)

    if not isBST(root):
        print(0)
        continue

    mismatch = []
    if not compareTrees(root, duplicate, mismatch):
        print(0)
        continue

    if len(mismatch) != 2 or mismatch[0][0] != mismatch[1][1] or mismatch[0][1] != mismatch[1][0]:
        print(0)
    else:
        print(1)

    print("~")
