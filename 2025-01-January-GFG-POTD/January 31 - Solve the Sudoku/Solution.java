//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = 9;
            int matrix[][] = new int[n][n];
            // String st[] = read.readLine().trim().split("\\s+");
            int k = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ob.solveSudoku(matrix);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) System.out.print(matrix[i][j] + " ");
                System.out.println();
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find a solved Sudoku.
     static void solveSudoku(int[][] mat) {
        solveSudokuUtil(mat);
    }

    // Utility function to solve the Sudoku using backtracking
    private static boolean solveSudokuUtil(int[][] mat) {
        int row = -1;
        int col = -1;
        boolean empty = true;

        // Find an empty cell
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (mat[r][c] == 0) {
                    row = r;
                    col = c;
                    empty = false;
                    break;
                }
            }
            if (!empty) break;
        }

        // If no empty cell is found, the Sudoku is solved
        if (empty) return true;

        // Try digits from 1 to 9
        for (int num = 1; num <= 9; num++) {
            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num; // Place the number

                // Recursively call the function to continue solving
                if (solveSudokuUtil(mat)) return true;

                // If placing num doesn't lead to a solution, reset it
                mat[row][col] = 0;
            }
        }
        return false; // Trigger backtracking
    }

    // Function to check if placing num in mat[row][col] is valid
    private static boolean isSafe(int[][] mat, int row, int col, int num) {
        // Check the row and column
        for (int x = 0; x < 9; x++) {
            if (mat[row][x] == num || mat[x][col] == num) {
                return false;
            }
        }

        // Check the 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

}
