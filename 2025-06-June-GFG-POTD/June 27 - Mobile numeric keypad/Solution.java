class Solution {
    public int getCount(int n) {
        if (n == 1) return 10;

        // Define keypad moves for each digit
        int[][] moves = {
            {0, 8},       // from 0
            {1, 2, 4},    // from 1
            {2, 1, 3, 5}, // from 2
            {3, 2, 6},    // from 3
            {4, 1, 5, 7}, // from 4
            {5, 2, 4, 6, 8}, // from 5
            {6, 3, 5, 9}, // from 6
            {7, 4, 8},    // from 7
            {8, 5, 7, 9, 0}, // from 8
            {9, 6, 8}     // from 9
        };

        // Initialize DP table
        int[][] dp = new int[n + 1][10];

        // Base case: 1-length sequences
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }

        // Build the DP table
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit <= 9; digit++) {
                dp[len][digit] = 0;
                for (int neighbor : moves[digit]) {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }

        // Sum up all sequences of length n starting from any digit
        int total = 0;
        for (int i = 0; i <= 9; i++) {
            total += dp[n][i];
        }

        return total;
    }
}
