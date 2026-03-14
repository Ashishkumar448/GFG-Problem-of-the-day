from collections import deque

class Solution:
    def topView(self, root):
        if not root:
            return []

        mp = {}   # hd -> node value
        q = deque([(root, 0)])

        while q:
            node, hd = q.popleft()

            if hd not in mp:
                mp[hd] = node.data

            if node.left:
                q.append((node.left, hd - 1))

            if node.right:
                q.append((node.right, hd + 1))

        result = []
        for key in sorted(mp.keys()):
            result.append(mp[key])

        return result
