// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> board(n, -1);  // Array to store the position of queens
        solveNQueens(0, board, n, result);
        return result;
    }

private:
    void solveNQueens(int row, vector<int>& board, int n, vector<vector<int>>& result) {
        if (row == n) {
            vector<int> solution;
            for (int col : board) {
                solution.push_back(col + 1); // Convert 0-indexed to 1-indexed
            }
            result.push_back(solution);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row] = col;
                solveNQueens(row + 1, board, n, result);
            }
        }
    }

    bool isSafe(int row, int col, vector<int>& board) {
        for (int i = 0; i < row; i++) {
            // Check if any queen in previous rows attacks the current position
            if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << "-1" << endl;
        else {
            for (const auto& vec : ans) {
                cout << "[";
                for (int x : vec)
                    cout << x << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
