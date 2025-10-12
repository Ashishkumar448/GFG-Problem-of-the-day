class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.moves = 0

    def distCandy(self, root: Node) -> int:
        self.moves = 0
        self.dfs(root)
        return self.moves

    def dfs(self, node: Node) -> int:
        if not node:
            return 0

        left_balance = self.dfs(node.left)
        right_balance = self.dfs(node.right)

        self.moves += abs(left_balance) + abs(right_balance)

        # Return this node’s balance
        return node.data + left_balance + right_balance - 1
