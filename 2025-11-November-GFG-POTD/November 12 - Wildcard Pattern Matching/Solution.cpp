class Solution {
public:
    bool wildCard(string txt, string pat) {
        int n = pat.size();
        int m = txt.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base case: empty pattern and empty text
        dp[0][0] = true;
        
        // Handle patterns with '*' at the start
        for (int i = 1; i <= n; i++) {
            if (pat[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char p = pat[i - 1];
                char t = txt[j - 1];
                
                if (p == t || p == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};
