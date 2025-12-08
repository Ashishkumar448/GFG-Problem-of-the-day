class Solution {
public:
    string matrixChainOrder(int arr[], int n) {
        // dp[i][j] = minimum cost
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        string result = "";
        buildParenthesis(result, bracket, 1, n - 1);
        return result;
    }

private:
    void buildParenthesis(string &res, vector<vector<int>>& bracket, int i, int j) {
        if (i == j) {
            res.push_back('A' + i - 1);
            return;
        }

        res.push_back('(');
        buildParenthesis(res, bracket, i, bracket[i][j]);
        buildParenthesis(res, bracket, bracket[i][j] + 1, j);
        res.push_back(')');
    }
};
