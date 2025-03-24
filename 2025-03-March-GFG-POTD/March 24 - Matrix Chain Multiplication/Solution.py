class Solution:
    def matrixMultiplication(self, arr):
        n = len(arr)
        dp = [[0] * n for _ in range(n)]

        for length in range(2, n):  # Length of chain
            for i in range(1, n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')
                for k in range(i, j):
                    cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
                    dp[i][j] = min(dp[i][j], cost)

        return dp[1][n - 1]


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        print(obj.matrixMultiplication(arr))
        print("~")
