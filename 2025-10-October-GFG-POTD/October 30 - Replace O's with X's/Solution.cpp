#include <vector>
using namespace std;

class Solution {
public:
    void fill(vector<vector<char>>& grid) {
        if (grid.empty()) return;

        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Mark 'O's connected to border
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 'O') dfs(grid, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') dfs(grid, 0, j, n, m);
            if (grid[n - 1][j] == 'O') dfs(grid, n - 1, j, n, m);
        }

        // Step 2: Flip remaining 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 'O') return;

        grid[i][j] = '#'; // mark as safe

        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
};
