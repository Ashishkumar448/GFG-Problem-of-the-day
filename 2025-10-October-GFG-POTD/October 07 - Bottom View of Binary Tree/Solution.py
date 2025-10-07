from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def bottomView(self, root):
        result = []
        if not root:
            return result

        hd_map = {}  # horizontal distance -> node value
        queue = deque([(root, 0)])  # (node, hd)

        while queue:
            node, hd = queue.popleft()

            # Update the map (latest node at this hd)
            hd_map[hd] = node.data

            if node.left:
                queue.append((node.left, hd - 1))
            if node.right:
                queue.append((node.right, hd + 1))

        # Return values sorted by horizontal distance
        for hd in sorted(hd_map.keys()):
            result.append(hd_map[hd])

        return result
