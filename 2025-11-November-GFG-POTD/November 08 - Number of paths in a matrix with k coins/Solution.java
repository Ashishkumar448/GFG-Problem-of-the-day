class Solution {
    int n, m;
    int[][] mat;
    Integer[][][] dp;
    
    public int numberOfPath(int[][] mat, int k) {
        this.n = mat.length;
        this.m = mat[0].length;
        this.mat = mat;
        this.dp = new Integer[n][m][k + 1];
        return helper(0, 0, k);
    }
    
    private int helper(int i, int j, int k) {
        // Out of bounds
        if (i >= n || j >= m) return 0;
        
        // If at bottom-right
        if (i == n - 1 && j == m - 1) {
            return (k == mat[i][j]) ? 1 : 0;
        }
        
        // Memoization check
        if (dp[i][j][k] != null) return dp[i][j][k];
        
        // If current cell value > remaining sum
        if (k < mat[i][j]) return dp[i][j][k] = 0;
        
        // Move down and right
        int down = helper(i + 1, j, k - mat[i][j]);
        int right = helper(i, j + 1, k - mat[i][j]);
        
        dp[i][j][k] = down + right;
        return dp[i][j][k];
    }
}
