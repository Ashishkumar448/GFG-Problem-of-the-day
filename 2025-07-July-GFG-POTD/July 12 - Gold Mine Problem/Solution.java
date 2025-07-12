class Solution {
    public int maxGold(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        int[][] dp = new int[n][m];

        // Fill the last column with the given values
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = mat[i][m - 1];
        }

        // Fill the table from second-last column to the first
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int right = dp[i][j + 1]; // Right
                int rightUp = (i > 0) ? dp[i - 1][j + 1] : 0; // Diagonally up-right
                int rightDown = (i < n - 1) ? dp[i + 1][j + 1] : 0; // Diagonally down-right

                dp[i][j] = mat[i][j] + Math.max(right, Math.max(rightUp, rightDown));
            }
        }

        // The maximum value in the first column will be the result
        int maxGold = 0;
        for (int i = 0; i < n; i++) {
            maxGold = Math.max(maxGold, dp[i][0]);
        }

        return maxGold;
    }
}
