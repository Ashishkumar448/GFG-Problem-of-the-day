#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Directions for moving in the grid (right, down, left, up)
    int rowDir[4] = {0, 1, 0, -1};
    int colDir[4] = {1, 0, -1, 0};

    bool isWordExist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();

        // Iterate through all cells to start DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start DFS if the first character matches
                if (mat[i][j] == word[0]) {
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    if (dfs(mat, word, 0, i, j, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    // DFS helper function
    bool dfs(vector<vector<char>>& mat, string word, int index, int row, int col, vector<vector<bool>>& visited) {
        // If index matches word length, we've found the word
        if (index == word.size()) {
            return true;
        }

        // Check bounds and if the cell is already visited or doesn't match
        if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || visited[row][col] || mat[row][col] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Explore all 4 possible directions (right, down, left, up)
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDir[i];
            int newCol = col + colDir[i];
            if (dfs(mat, word, index + 1, newRow, newCol, visited)) {
                return true;
            }
        }

        // Backtrack: unmark the current cell as visited
        visited[row][col] = false;
        return false;
    }
};

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));

        // Reading the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        string word;
        cin >> word;

        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~\n";
    }

    return 0;
}
