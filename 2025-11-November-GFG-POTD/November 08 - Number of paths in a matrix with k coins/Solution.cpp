#include <vector>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> mat;
    vector<vector<vector<int>>> dp;

    int helper(int i, int j, int k) {
        // Out of bounds
        if (i >= n || j >= m) return 0;

        // If at bottom-right
        if (i == n - 1 && j == m - 1)
            return (k == mat[i][j]) ? 1 : 0;

        // Memoization check
        if (dp[i][j][k] != -1) return dp[i][j][k];

        // If current cell value > remaining sum
        if (k < mat[i][j]) return dp[i][j][k] = 0;

        // Move down and right
        int down = helper(i + 1, j, k - mat[i][j]);
        int right = helper(i, j + 1, k - mat[i][j]);

        dp[i][j][k] = down + right;
        return dp[i][j][k];
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        this->n = mat.size();
        this->m = mat[0].size();
        this->mat = mat;
        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return helper(0, 0, k);
    }
};
