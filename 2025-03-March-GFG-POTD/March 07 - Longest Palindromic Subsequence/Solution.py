class Solution:
    def longestPalinSubseq(self, s: str) -> int:
        rev = s[::-1]  # Reverse the string
        n = len(s)
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        # Finding LCS between s and its reverse
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if s[i - 1] == rev[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[n][n]

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.longestPalinSubseq(s))
        print("~")
