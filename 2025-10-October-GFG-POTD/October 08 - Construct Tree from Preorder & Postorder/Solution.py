class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.preIndex = 0
        self.postMap = {}

    def constructTree(self, pre, post):
        # Map value -> index in postorder
        for i, val in enumerate(post):
            self.postMap[val] = i
        return self._build(pre, post, 0, len(post) - 1)

    def _build(self, pre, post, l, r):
        if self.preIndex >= len(pre) or l > r:
            return None

        root = Node(pre[self.preIndex])
        self.preIndex += 1

        if l == r or self.preIndex >= len(pre):
            return root

        postIndex = self.postMap[pre[self.preIndex]]

        root.left = self._build(pre, post, l, postIndex)
        root.right = self._build(pre, post, postIndex + 1, r - 1)

        return root
