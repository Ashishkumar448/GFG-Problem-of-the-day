class Solution {
    static final int MOD = 1000000007;

    int distinctSubseq(String str) {
        int n = str.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;   // empty subsequence

        // store last occurrence (1-based index) of each character
        int[] last = new int[26];

        for (int i = 1; i <= n; i++) {
            char c = str.charAt(i - 1);
            dp[i] = (2 * dp[i - 1]) % MOD;

            int prev = last[c - 'a'];
            if (prev > 0) {
                dp[i] = (dp[i] - dp[prev - 1] + MOD) % MOD;
            }

            last[c - 'a'] = i;
        }

        return (int) dp[n];
    }
}
