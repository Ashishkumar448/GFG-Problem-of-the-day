class Solution {
public:
    int minSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // base case
        
        for (int i = 1; i <= n; i++) {
            dp[i] = i; // worst case: all 1^2
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
