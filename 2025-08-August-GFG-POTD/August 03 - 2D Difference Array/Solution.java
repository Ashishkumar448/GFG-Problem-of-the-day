class Solution {
    public ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr) {
        int n = mat.length;
        int m = mat[0].length;

        // Step 1: Initialize diff matrix
        int[][] diff = new int[n + 2][m + 2]; // extra row/col to avoid bounds check

        // Step 2: Apply operations to diff matrix
        for (int[] op : opr) {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            diff[r1][c1] += val;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= val;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= val;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += val;
        }

        // Step 3: 2D Prefix sum over rows
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // Step 4: 2D Prefix sum over columns
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Step 5: Add diff to original mat and prepare result
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                row.add(mat[i][j] + diff[i][j]);
            }
            res.add(row);
        }

        return res;
    }
}
