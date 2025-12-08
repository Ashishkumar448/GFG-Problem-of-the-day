class Solution {
    public String matrixChainOrder(int arr[]) {
        int n = arr.length;

        // dp[i][j] = minimum number of multiplications needed
        int dp[][] = new int[n][n];

        // bracket[i][j] = position of k at which optimal split occurs
        int bracket[][] = new int[n][n];

        // Cost is zero when multiplying one matrix
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;   // store k for optimal split
                    }
                }
            }
        }

        // Build the string answer
        StringBuilder result = new StringBuilder();
        buildParenthesis(result, bracket, 1, n - 1);
        return result.toString();
    }

    // Recursively build the string
    private void buildParenthesis(StringBuilder sb, int bracket[][], int i, int j) {
        if (i == j) {
            sb.append((char)('A' + i - 1));
            return;
        }

        sb.append("(");
        buildParenthesis(sb, bracket, i, bracket[i][j]);
        buildParenthesis(sb, bracket, bracket[i][j] + 1, j);
        sb.append(")");
    }
}
