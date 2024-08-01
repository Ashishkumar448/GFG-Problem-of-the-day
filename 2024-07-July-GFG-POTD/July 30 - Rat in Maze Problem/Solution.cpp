#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    int n = maze.size();
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y];
}

void findPathsUtil(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& paths) {
    int n = maze.size();
    
    // If destination (bottom-right corner) is reached
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }
    
    // Mark the cell as visited
    visited[x][y] = true;
    
    // Move in all four possible directions
    char move[4] = {'D', 'L', 'R', 'U'};
    int row[4] = {1, 0, 0, -1};
    int col[4] = {0, -1, 1, 0};
    
    for (int k = 0; k < 4; k++) {
        int nextX = x + row[k];
        int nextY = y + col[k];
        
        if (isSafe(nextX, nextY, maze, visited)) {
            findPathsUtil(nextX, nextY, maze, visited, path + move[k], paths);
        }
    }
    
    // Unmark the cell (backtracking)
    visited[x][y] = false;
}

vector<string> findPath(vector<vector<int>>& maze) {
    vector<string> paths;
    int n = maze.size();
    
    // If starting cell itself is blocked
    if (maze[0][0] == 0) return paths;
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    findPathsUtil(0, 0, maze, visited, "", paths);
    
    return paths;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> maze(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        
        vector<string> result = findPath(maze);
        sort(result.begin(), result.end());
        
        if (!result.empty()) {
            for (const string& path : result) {
                cout << path << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
