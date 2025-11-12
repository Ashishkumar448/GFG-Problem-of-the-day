class Solution:
    def wildCard(self, txt: str, pat: str) -> bool:
        n = len(pat)
        m = len(txt)
        
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        
        # Base case: empty pattern and empty text
        dp[0][0] = True
        
        # Handle patterns with '*' at the start
        for i in range(1, n + 1):
            if pat[i - 1] == '*':
                dp[i][0] = dp[i - 1][0]
        
        # Fill the DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                p = pat[i - 1]
                t = txt[j - 1]
                
                if p == t or p == '?':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p == '*':
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
                else:
                    dp[i][j] = False
        
        return dp[n][m]
