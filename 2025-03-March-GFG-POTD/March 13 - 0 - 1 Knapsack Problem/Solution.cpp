# { Driver Code Starts
class Solution:
    @staticmethod
    def knapsack(W, val, wt):
        n = len(val)
        dp = [[0] * (W + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for w in range(W + 1):
                if wt[i - 1] <= w:
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])
                else:
                    dp[i][w] = dp[i - 1][w]

        return dp[n][W]


if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        W = int(input())
        val = list(map(int, input().split()))
        wt = list(map(int, input().split()))
        print(Solution.knapsack(W, val, wt))
        print("~")
# } Driver Code Ends
