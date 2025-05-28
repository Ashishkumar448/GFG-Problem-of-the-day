class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // 2D array to store seen column pairs
        vector<vector<bool>> colPairs(m, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int col1 = 0; col1 < m; col1++) {
                if (mat[i][col1] == 1) {
                    for (int col2 = col1 + 1; col2 < m; col2++) {
                        if (mat[i][col2] == 1) {
                            if (colPairs[col1][col2]) {
                                return true;
                            }
                            colPairs[col1][col2] = true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
