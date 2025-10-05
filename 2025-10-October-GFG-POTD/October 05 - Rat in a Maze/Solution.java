class Solution {
    public ArrayList<String> ratInMaze(int[][] maze) {
        ArrayList<String> result = new ArrayList<>();
        int n = maze.length;
        
        // If start or destination is blocked, no path
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) 
            return result;
        
        boolean[][] visited = new boolean[n][n];
        backtrack(0, 0, maze, n, "", visited, result);
        Collections.sort(result);  // ensure lexicographic order
        return result;
    }

    private void backtrack(int i, int j, int[][] maze, int n, String path, boolean[][] visited, ArrayList<String> result) {
        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            result.add(path);
            return;
        }

        // Mark current cell as visited
        visited[i][j] = true;

        // Direction vectors & order: D, L, R, U
        int[] di = {1, 0, 0, -1};
        int[] dj = {0, -1, 1, 0};
        char[] dir = {'D', 'L', 'R', 'U'};

        for (int k = 0; k < 4; k++) {
            int nextI = i + di[k];
            int nextJ = j + dj[k];
            if (isSafe(nextI, nextJ, maze, visited, n)) {
                backtrack(nextI, nextJ, maze, n, path + dir[k], visited, result);
            }
        }

        // Backtrack (unmark)
        visited[i][j] = false;
    }

    private boolean isSafe(int i, int j, int[][] maze, boolean[][] visited, int n) {
        return (i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 1 && !visited[i][j]);
    }
}
