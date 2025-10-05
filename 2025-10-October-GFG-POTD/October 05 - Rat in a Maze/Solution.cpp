#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>> &maze) {
        vector<string> result;
        int n = maze.size();

        // If start or destination is blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(0, 0, maze, n, "", visited, result);
        sort(result.begin(), result.end()); // lexicographic order
        return result;
    }

private:
    void backtrack(int i, int j, vector<vector<int>> &maze, int n, string path,
                   vector<vector<bool>> &visited, vector<string> &result) {
        // Base case
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        visited[i][j] = true;

        // Directions: D, L, R, U
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (isSafe(ni, nj, maze, visited, n)) {
                backtrack(ni, nj, maze, n, path + dir[k], visited, result);
            }
        }

        visited[i][j] = false; // backtrack
    }

    bool isSafe(int i, int j, vector<vector<int>> &maze, vector<vector<bool>> &visited, int n) {
        return (i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 1 && !visited[i][j]);
    }
};
