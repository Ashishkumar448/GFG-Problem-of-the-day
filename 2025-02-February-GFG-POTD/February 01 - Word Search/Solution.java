//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(); // Number of test cases
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] mat = new char[n][m];

            // Reading the matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = sc.next().charAt(0);
                }
            }

            String word = sc.next();
            Solution obj = new Solution();
            boolean ans = obj.isWordExist(mat, word);
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    // Directions arrays for moving in the grid (right, down, left, up)
    private static final int[] rowDir = {0, 1, 0, -1};
    private static final int[] colDir = {1, 0, -1, 0};

    public boolean isWordExist(char[][] mat, String word) {
        int n = mat.length;
        int m = mat[0].length;

        // Iterate through all cells to start DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start DFS if the first character matches
                if (mat[i][j] == word.charAt(0)) {
                    boolean[][] visited = new boolean[n][m];
                    if (dfs(mat, word, 0, i, j, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // DFS helper function
    private boolean dfs(char[][] mat, String word, int index, int row, int col, boolean[][] visited) {
        // If index matches word length, we've found the word
        if (index == word.length()) {
            return true;
        }

        // Check bounds and if the cell is already visited or doesn't match
        if (row < 0 || col < 0 || row >= mat.length || col >= mat[0].length || visited[row][col] || mat[row][col] != word.charAt(index)) {
            return false;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Explore all 4 possible directions (right, down, left, up)
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDir[i];
            int newCol = col + colDir[i];
            if (dfs(mat, word, index + 1, newRow, newCol, visited)) {
                return true;
            }
        }

        // Backtrack: unmark the current cell as visited
        visited[row][col] = false;
        return false;
    }
}
