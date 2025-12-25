class Solution {
    public ArrayList<Integer> findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        int low = 0, high = m - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Find row index of maximum element in mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : Integer.MIN_VALUE;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : Integer.MIN_VALUE;
            
            // Check peak condition
            if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right) {
                ArrayList<Integer> ans = new ArrayList<>();
                ans.add(maxRow);
                ans.add(mid);
                return ans;
            } 
            // Move search space
            else if (left > mat[maxRow][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return new ArrayList<>(); // This will never be reached as a peak always exists
    }
}
