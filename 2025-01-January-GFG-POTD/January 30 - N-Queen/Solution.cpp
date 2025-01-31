#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> results;
        vector<int> board(n); // board[i] = row position of queen in column i
        solveNQueens(n, 0, board, results);
        return results;
    }

private:
    void solveNQueens(int n, int col, vector<int>& board, vector<vector<int>>& results) {
        if (col == n) {
            // A valid configuration is found; add it to results
            vector<int> solution(n);
            for (int i = 0; i < n; i++) {
                solution[i] = board[i] + 1; // converting to 1-based index
            }
            results.push_back(solution);
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

    bool isSafe(int row, int col, const vector<int>& board) {
        for (int i = 0; i < col; i++) {
            // Check if the queen can be attacked
            if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 4; // Change this value to test with different sizes
    vector<vector<int>> solutions = sol.nQueen(n);
    
    for (const auto& solution : solutions) {
        cout << "[";
        for (int pos : solution) {
            cout << pos << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
