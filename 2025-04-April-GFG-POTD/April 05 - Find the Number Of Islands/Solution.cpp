#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) {
        visited[x][y] = true;

        for (int dir = 0; dir < 8; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (isValid(newX, newY, n, m) && grid[newX][newY] == 'L' && !visited[newX][newY]) {
                dfs(grid, visited, newX, newY, n, m);
            }
        }
    }

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        Solution obj;
        cout << obj.countIslands(grid) << endl;
        cout << "~" << endl;
    }
    return 0;
}
