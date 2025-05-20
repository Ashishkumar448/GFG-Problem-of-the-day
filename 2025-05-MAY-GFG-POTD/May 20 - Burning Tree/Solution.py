class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

from collections import deque

def buildTree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    q = deque([root])

    i = 1
    while q and i < len(ip):
        curr = q.popleft()

        if ip[i] != 'N':
            curr.left = Node(int(ip[i]))
            q.append(curr.left)
        i += 1

        if i >= len(ip):
            break

        if ip[i] != 'N':
            curr.right = Node(int(ip[i]))
            q.append(curr.right)
        i += 1

    return root

class Solution:
    def minTime(self, root, target):
        parent_map = {}

        def markParents(node, parent=None):
            if not node:
                return
            if parent:
                parent_map[node] = parent
            markParents(node.left, node)
            markParents(node.right, node)

        def findTarget(node, target):
            if not node:
                return None
            if node.data == target:
                return node
            left = findTarget(node.left, target)
            return left if left else findTarget(node.right, target)

        markParents(root)
        target_node = findTarget(root, target)

        q = deque([target_node])
        visited = set([target_node])
        time = -1

        while q:
            size = len(q)
            burnt_next = False

            for _ in range(size):
                curr = q.popleft()

                for neighbor in (curr.left, curr.right, parent_map.get(curr)):
                    if neighbor and neighbor not in visited:
                        q.append(neighbor)
                        visited.add(neighbor)
                        burnt_next = True

            if burnt_next:
                time += 1

        return time + 1

# For testing
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        target = int(input())
        root = buildTree(s)
        sol = Solution()
        print(sol.minTime(root, target))
