class Solution {
public:
    bool isWordExist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (dfs(mat, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& mat, string& word,
             int i, int j, int index,
             vector<vector<bool>>& visited) {

        // All characters matched
        if (index == word.size()) {
            return true;
        }

        // Boundary and mismatch checks
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() ||
            visited[i][j] || mat[i][j] != word[index]) {
            return false;
        }

        visited[i][j] = true;

        bool found =
            dfs(mat, word, i + 1, j, index + 1, visited) ||
            dfs(mat, word, i - 1, j, index + 1, visited) ||
            dfs(mat, word, i, j + 1, index + 1, visited) ||
            dfs(mat, word, i, j - 1, index + 1, visited);

        visited[i][j] = false;  // backtrack

        return found;
    }
};
