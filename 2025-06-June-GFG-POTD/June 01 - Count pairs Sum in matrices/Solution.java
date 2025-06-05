class Solution {
    int countPairs(int[][] mat1, int[][] mat2, int x) {
        int n = mat1.length;
        Set<Integer> set = new HashSet<>();
        
        // Step 1: Add all elements from mat2 to the set
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set.add(mat2[i][j]);
            }
        }
        
        int count = 0;
        
        // Step 2: For each element in mat1, check if x - a exists in set
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = mat1[i][j];
                int b = x - a;
                if (set.contains(b)) {
                    count++;
                }
            }
        }
        
        return count;
    }
}
