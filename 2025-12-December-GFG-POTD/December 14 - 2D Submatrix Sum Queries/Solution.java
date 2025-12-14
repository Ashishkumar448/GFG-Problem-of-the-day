class Solution {
    public ArrayList<Integer> prefixSum2D(int[][] mat, int[][] queries) {
        int n = mat.length;
        int m = mat[0].length;

        // Use long to avoid overflow
        long[][] pre = new long[n + 1][m + 1];

        // Build prefix sum (1-based indexing)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        // Pre-size ArrayList to avoid resizing
        ArrayList<Integer> ans = new ArrayList<>(queries.length);

        // Answer queries
        for (int[] q : queries) {
            int r1 = q[0] + 1;
            int c1 = q[1] + 1;
            int r2 = q[2] + 1;
            int c2 = q[3] + 1;

            long sum = pre[r2][c2]
                     - pre[r1 - 1][c2]
                     - pre[r2][c1 - 1]
                     + pre[r1 - 1][c1 - 1];

            ans.add((int) sum);
        }

        return ans;
    }
}
