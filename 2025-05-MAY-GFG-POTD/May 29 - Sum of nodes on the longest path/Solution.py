class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    class Result:
        def __init__(self):
            self.maxLen = 0
            self.maxSum = 0

    def sumOfLongRootToLeafPath(self, root):
        res = self.Result()
        self.dfs(root, 0, 0, res)
        return res.maxSum

    def dfs(self, node, currLen, currSum, res):
        if node is None:
            return

        currSum += node.data
        currLen += 1

        if node.left is None and node.right is None:
            if currLen > res.maxLen:
                res.maxLen = currLen
                res.maxSum = currSum
            elif currLen == res.maxLen:
                res.maxSum = max(res.maxSum, currSum)

        self.dfs(node.left, currLen, currSum, res)
        self.dfs(node.right, currLen, currSum, res)
