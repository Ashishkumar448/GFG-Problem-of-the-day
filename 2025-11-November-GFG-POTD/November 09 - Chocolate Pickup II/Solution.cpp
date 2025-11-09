class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size();
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
            return 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        int ans = max(0, dfs(mat, 0, 0, 0, dp));
        return ans;
    }

private:
    int dfs(vector<vector<int>>& mat, int r1, int c1, int r2, vector<vector<vector<int>>>& dp) {
        int n = mat.size();
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        if (dp[r1][c1][r2] != INT_MIN)
            return dp[r1][c1][r2];

        int chocolates = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
            chocolates += mat[r2][c2];

        int next = max({
            dfs(mat, r1 + 1, c1, r2 + 1, dp),
            dfs(mat, r1, c1 + 1, r2, dp),
            dfs(mat, r1 + 1, c1, r2, dp),
            dfs(mat, r1, c1 + 1, r2 + 1, dp)
        });

        chocolates += next;
        dp[r1][c1][r2] = chocolates;
        return chocolates;
    }
};
