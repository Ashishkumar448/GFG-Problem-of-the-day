class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>>& mat,
                            vector<vector<int>>& queries) {

        int n = mat.size();
        int m = mat[0].size();

        // long long to avoid overflow
        vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0));

        // Build prefix sum (1-based indexing)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // Answer queries
        for (auto &q : queries) {
            int r1 = q[0] + 1;
            int c1 = q[1] + 1;
            int r2 = q[2] + 1;
            int c2 = q[3] + 1;

            long long sum = pre[r2][c2]
                          - pre[r1 - 1][c2]
                          - pre[r2][c1 - 1]
                          + pre[r1 - 1][c1 - 1];

            ans.push_back((int)sum);
        }

        return ans;
    }
};
