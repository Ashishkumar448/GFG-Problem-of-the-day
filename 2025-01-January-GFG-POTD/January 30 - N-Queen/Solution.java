import java.util.ArrayList;

class Solution {
    public ArrayList<ArrayList<Integer>> nQueen(int n) {
        ArrayList<ArrayList<Integer>> results = new ArrayList<>();
        int[] board = new int[n]; // board[i] = row position of queen in column i
        solveNQueens(n, 0, board, results);
        return results;
    }

    private void solveNQueens(int n, int col, int[] board, ArrayList<ArrayList<Integer>> results) {
        if (col == n) {
            // A valid configuration is found; add it to results
            ArrayList<Integer> solution = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                solution.add(board[i] + 1); // converting to 1-based index
            }
            results.add(solution);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board)) {
                board[col] = row; // Place queen
                solveNQueens(n, col + 1, board, results); // Recur to place rest of the queens
                // No need to remove the queen as we are overwriting the position on next iteration
            }
        }
    }

    private boolean isSafe(int row, int col, int[] board) {
        for (int i = 0; i < col; i++) {
            // Check if the queen can be attacked
            if (board[i] == row || Math.abs(board[i] - row) == Math.abs(i - col)) {
                return false;
            }
        }
        return true;
    }
}
