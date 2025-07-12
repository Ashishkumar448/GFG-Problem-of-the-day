class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> mat) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the last column
        for (int i = 0; i < n; ++i)
            dp[i][m - 1] = mat[i][m - 1];

        // Fill the table from second-last column to the first
        for (int j = m - 2; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                int right = dp[i][j + 1];
                int rightUp = (i > 0) ? dp[i - 1][j + 1] : 0;
                int rightDown = (i < n - 1) ? dp[i + 1][j + 1] : 0;

                dp[i][j] = mat[i][j] + max({right, rightUp, rightDown});
            }
        }

        // Find the maximum gold from the first column
        int maxGold = 0;
        for (int i = 0; i < n; ++i)
            maxGold = max(maxGold, dp[i][0]);

        return maxGold;
    }
};
