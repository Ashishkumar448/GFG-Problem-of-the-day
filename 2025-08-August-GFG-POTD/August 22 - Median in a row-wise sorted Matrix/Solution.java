class Solution {
    public int median(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        
        // Find minimum and maximum
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            min = Math.min(min, mat[i][0]);
            max = Math.max(max, mat[i][m - 1]);
        }
        
        int desired = (n * m + 1) / 2; // position of median
        
        while (min < max) {
            int mid = (min + max) / 2;
            int count = 0;
            
            // Count elements <= mid in each row
            for (int i = 0; i < n; i++) {
                count += countSmallerEqual(mat[i], mid);
            }
            
            if (count < desired) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        
        return min;
    }
    
    // Binary search in a row to count elements <= target
    private int countSmallerEqual(int[] row, int target) {
        int l = 0, r = row.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (row[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l; // number of elements <= target
    }
}
