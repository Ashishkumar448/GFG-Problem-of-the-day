#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find a solved Sudoku
    void solveSudoku(int mat[9][9]) {
        solveSudokuUtil(mat);
    }

private:
    // Utility function to solve the Sudoku using backtracking
    bool solveSudokuUtil(int mat[9][9]) {
        int row = -1, col = -1;
        bool empty = true;

        // Find an empty cell (represented by 0)
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
    bool isSafe(int mat[9][9], int row, int col, int num) {
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
};

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int mat[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        ob.solveSudoku(mat);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}
