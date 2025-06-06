class Solution {
public:
    static int minDeletions(string s) {
        int n = s.length();
        string rev = string(s.rbegin(), s.rend());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill dp table for LCS between s and rev
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lpsLength = dp[n][n];
        return n - lpsLength;
    }
};
