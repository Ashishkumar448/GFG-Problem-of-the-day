class Solution {
    int findWays(int n) {
        // If length is odd, no valid parentheses possible
        if (n % 2 != 0) return 0;

        int pairs = n / 2;

        int[] dp = new int[pairs + 1];
        dp[0] = 1;

        for (int i = 1; i <= pairs; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[pairs];
    }
}
