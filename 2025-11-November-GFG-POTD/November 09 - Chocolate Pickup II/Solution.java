class Solution {
    public int chocolatePickup(int[][] mat) {
        int n = mat.length;
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
            return 0;

        Integer[][][] dp = new Integer[n][n][n];
        int ans = Math.max(0, dfs(mat, 0, 0, 0, dp));
        return ans;
    }

    private int dfs(int[][] mat, int r1, int c1, int r2, Integer[][][] dp) {
        int n = mat.length;
        int c2 = r1 + c1 - r2;

        // Check bounds and blocked cells
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return Integer.MIN_VALUE;

        // Base case: both reached the destination
        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        if (dp[r1][c1][r2] != null)
            return dp[r1][c1][r2];

        int chocolates = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
            chocolates += mat[r2][c2];

        // Try all move combinations
        int next = Math.max(
            Math.max(dfs(mat, r1 + 1, c1, r2 + 1, dp), dfs(mat, r1, c1 + 1, r2, dp)),
            Math.max(dfs(mat, r1 + 1, c1, r2, dp), dfs(mat, r1, c1 + 1, r2 + 1, dp))
        );

        chocolates += next;
        dp[r1][c1][r2] = chocolates;
        return chocolates;
    }
}
