#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool isSafe(int x, int y, vector<vector<int>>& board, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
    }

    bool solveKT(int x, int y, int movei, vector<vector<int>>& board, int n) {
        if (movei == n * n)
            return true;

        for (int k = 0; k < 8; k++) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isSafe(nextX, nextY, board, n)) {
                board[nextX][nextY] = movei;
                if (solveKT(nextX, nextY, movei + 1, board, n))
                    return true;
                else
                    board[nextX][nextY] = -1; // backtrack
            }
        }
        return false;
    }

public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0;

        if (solveKT(0, 0, 1, board, n))
            return board;
        else
            return {{-1}};
    }
};

// Example usage
/*
int main() {
    Solution sol;
    int n = 5;
    auto res = sol.knightTour(n);
    for (auto& row : res) {
        for (int x : row) cout << setw(3) << x << " ";
        cout << endl;
    }
}
*/
