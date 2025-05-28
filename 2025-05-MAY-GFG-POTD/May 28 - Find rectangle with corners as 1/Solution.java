class Solution {
    public boolean ValidCorner(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        // Map to store column pairs seen in previous rows
        boolean[][] colPairs = new boolean[m][m];

        // Loop through all rows
        for (int i = 0; i < n; i++) {
            // Find all pairs of columns in the current row that have 1s
            for (int col1 = 0; col1 < m; col1++) {
                if (mat[i][col1] == 1) {
                    for (int col2 = col1 + 1; col2 < m; col2++) {
                        if (mat[i][col2] == 1) {
                            // If we have seen this pair in any previous row, rectangle found
                            if (colPairs[col1][col2]) {
                                return true;
                            }
                            // Mark this pair as seen
                            colPairs[col1][col2] = true;
                        }
                    }
                }
            }
        }
        return false; // No rectangle found
    }
}
