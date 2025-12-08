class Solution:
    def matrixChainOrder(self, arr):
        n = len(arr)
        
        # dp[i][j] stores minimum cost
        dp = [[0] * n for _ in range(n)]
        bracket = [[0] * n for _ in range(n)]

        for length in range(2, n):
            for i in range(1, n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')

                for k in range(i, j):
                    cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
                    if cost < dp[i][j]:
                        dp[i][j] = cost
                        bracket[i][j] = k

        res = []
        self.build(bracket, 1, n - 1, res)
        return ''.join(res)

    def build(self, bracket, i, j, res):
        if i == j:
            res.append(chr(ord('A') + i - 1))
            return

        res.append('(')
        self.build(bracket, i, bracket[i][j], res)
        self.build(bracket, bracket[i][j] + 1, j, res)
        res.append(')')
