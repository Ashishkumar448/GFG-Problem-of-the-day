class Solution:
    def wildCard(self, pattern, string):
        n = len(string)
        m = len(pattern)

        # Create a DP table with default value False
        dp = [[False] * (m + 1) for _ in range(n + 1)]

        # Empty pattern can match with empty string
        dp[0][0] = True

        # Only '*' can match with empty string
        for j in range(1, m + 1):
            if pattern[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]

        # Fill the DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if pattern[j - 1] == '*':
                    # '*' can match with or without the current character of str
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
                elif pattern[j - 1] == '?' or pattern[j - 1] == string[i - 1]:
                    # '?' or exact match
                    dp[i][j] = dp[i - 1][j - 1]

        # Return the result
        return 1 if dp[n][m] else 0

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        pattern = input().strip()
        string = input().strip()
        sol = Solution()
        print(sol.wildCard(pattern, string))
