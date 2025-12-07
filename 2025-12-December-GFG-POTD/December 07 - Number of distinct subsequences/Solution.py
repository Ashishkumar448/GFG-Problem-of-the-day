class Solution:
    MOD = 1000000007
    
    def distinctSubseq(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1  # empty subsequence

        last = [0] * 26  # last occurrence (1-based index)

        for i in range(1, n + 1):
            c = s[i - 1]
            dp[i] = (2 * dp[i - 1]) % self.MOD

            prev = last[ord(c) - ord('a')]
            if prev > 0:
                dp[i] = (dp[i] - dp[prev - 1] + self.MOD) % self.MOD

            last[ord(c) - ord('a')] = i

        return dp[n]

