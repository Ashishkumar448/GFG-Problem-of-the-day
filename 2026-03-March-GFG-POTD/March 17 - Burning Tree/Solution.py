from collections import deque

class Solution:
    def minTime(self, root, target):
        parent_map = {}
        target_node = self.buildParentMap(root, parent_map, target)

        q = deque([target_node])
        visited = set([target_node])

        time = 0

        while q:
            size = len(q)
            burned = False

            for _ in range(size):
                curr = q.popleft()

                # left
                if curr.left and curr.left not in visited:
                    q.append(curr.left)
                    visited.add(curr.left)
                    burned = True

                # right
                if curr.right and curr.right not in visited:
                    q.append(curr.right)
                    visited.add(curr.right)
                    burned = True

                # parent
                if curr in parent_map and parent_map[curr] not in visited:
                    q.append(parent_map[curr])
                    visited.add(parent_map[curr])
                    burned = True

            if burned:
                time += 1

        return time

    def buildParentMap(self, root, parent_map, target):
        q = deque([root])
        target_node = None

        while q:
            curr = q.popleft()

            if curr.data == target:
                target_node = curr

            if curr.left:
                parent_map[curr.left] = curr
                q.append(curr.left)

            if curr.right:
                parent_map[curr.right] = curr
                q.append(curr.right)

        return target_node
