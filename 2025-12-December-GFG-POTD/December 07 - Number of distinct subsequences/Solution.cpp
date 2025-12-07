class Solution {
public:
    const int MOD = 1000000007;

    int distinctSubseq(string str) {
        int n = str.length();
        vector<long long> dp(n + 1);
        dp[0] = 1;  // empty subsequence

        vector<int> last(26, 0); // last occurrence (1-based index)

        for (int i = 1; i <= n; i++) {
            char c = str[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;

            int prev = last[c - 'a'];
            if (prev > 0) {
                dp[i] = (dp[i] - dp[prev - 1] + MOD) % MOD;
            }

            last[c - 'a'] = i;
        }

        return dp[n];
    }
};
