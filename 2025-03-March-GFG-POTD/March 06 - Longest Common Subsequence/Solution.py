class Solution:
    def lcs(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Fill the DP table using bottom-up approach
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]

# Driver Code
if __name__ == "__main__":
    test = int(input())
    for _ in range(test):
        s1 = input().strip()
        s2 = input().strip()
        obj = Solution()
        print(obj.lcs(s1, s2))
        print("~")
