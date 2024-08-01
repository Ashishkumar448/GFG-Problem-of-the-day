import java.util.*;

class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

class Solution {
    private static final int[] row = {1, 0, 0, -1};  // D, L, R, U
    private static final int[] col = {0, -1, 1, 0};
    private static final char[] move = {'D', 'L', 'R', 'U'};
    
    private boolean isSafe(int x, int y, int[][] mat, boolean[][] visited) {
        int n = mat.length;
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }
    
    private void findPathUtil(int x, int y, int[][] mat, boolean[][] visited, String path, ArrayList<String> result) {
        int n = mat.length;
        
        // If destination (bottom-right corner) is reached
        if (x == n - 1 && y == n - 1) {
            result.add(path);
            return;
        }
        
        // Mark the cell as visited
        visited[x][y] = true;
        
        // Move in all four possible directions
        for (int k = 0; k < 4; k++) {
            int nextX = x + row[k];
            int nextY = y + col[k];
            
            if (isSafe(nextX, nextY, mat, visited)) {
                findPathUtil(nextX, nextY, mat, visited, path + move[k], result);
            }
        }
        
        // Unmark the cell (backtracking)
        visited[x][y] = false;
    }
    
    public ArrayList<String> findPath(int[][] mat) {
        ArrayList<String> result = new ArrayList<>();
        int n = mat.length;
        
        // If starting cell itself is blocked
        if (mat[0][0] == 0) return result;
        
        boolean[][] visited = new boolean[n][n];
        
        findPathUtil(0, 0, mat, visited, "", result);
        
        return result;
    }
}
