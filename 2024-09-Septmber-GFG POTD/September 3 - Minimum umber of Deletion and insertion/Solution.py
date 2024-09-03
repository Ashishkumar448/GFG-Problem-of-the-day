# { Driver Code Starts
class Solution:
    def minOperations(self, str1, str2):
        m = len(str1)
        n = len(str2)
        lcs_length = self.longest_common_subsequence(str1, str2, m, n)

        # Calculate the number of deletions and insertions
        deletions = m - lcs_length
        insertions = n - lcs_length

        # Total operations needed
        return deletions + insertions

    def longest_common_subsequence(self, s1, s2, m, n):
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Build the dp array from bottom up
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]  # Length of LCS


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s1 = input()
        s2 = input()
        ob = Solution()
        print(ob.minOperations(s1, s2))
# } Driver Code Ends
