class Solution {
public:
    int minCost(int keys[], int freq[], int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // prefix frequency sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + freq[i];
        }

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;
                int sum = prefix[j + 1] - prefix[i];

                for (int r = i; r <= j; r++) {
                    int left = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;
                    dp[i][j] = min(dp[i][j], left + right + sum);
                }
            }
        }

        return dp[0][n - 1];
    }
};
