class Solution {
    static ArrayList<Integer> diagView(int mat[][]) {
        int n = mat.length;
        ArrayList<Integer> res = new ArrayList<>();
        
        // Loop over all diagonals
        for (int d = 0; d < 2 * n - 1; d++) {
            
            // Row index starts from 0 or (d - n + 1)
            int row = (d < n) ? 0 : d - n + 1;
            
            // Column index starts from d or n-1
            int col = (d < n) ? d : n - 1;
            
            // Traverse the diagonal
            while (row < n && col >= 0) {
                res.add(mat[row][col]);
                row++;
                col--;
            }
        }
        
        return res;
    }
}
