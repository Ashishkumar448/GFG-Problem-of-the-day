class Solution {
    public boolean isWordExist(char[][] mat, String word) {
        int n = mat.length;
        int m = mat[0].length;
        
        boolean[][] visited = new boolean[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word.charAt(0)) {
                    if (dfs(mat, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    private boolean dfs(char[][] mat, String word, int i, int j, int index, boolean[][] visited) {
        // If all characters are matched
        if (index == word.length()) {
            return true;
        }
        
        // Boundary and mismatch checks
        if (i < 0 || j < 0 || i >= mat.length || j >= mat[0].length ||
            visited[i][j] || mat[i][j] != word.charAt(index)) {
            return false;
        }
        
        // Mark current cell as visited
        visited[i][j] = true;
        
        // Explore all 4 directions
        boolean found = dfs(mat, word, i + 1, j, index + 1, visited) ||
                        dfs(mat, word, i - 1, j, index + 1, visited) ||
                        dfs(mat, word, i, j + 1, index + 1, visited) ||
                        dfs(mat, word, i, j - 1, index + 1, visited);
        
        // Backtrack
        visited[i][j] = false;
        
        return found;
    }
}
