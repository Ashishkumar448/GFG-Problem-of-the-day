class Solution {
public:
    int maxScore(string s, vector<vector<char>>& jumps) {
        if (s.empty()) return 0;
        const int ALPHA = 26;
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = s[i];

        // build adjacency
        vector<vector<bool>> allowed(ALPHA, vector<bool>(ALPHA, false));
        for (int i = 0; i < ALPHA; ++i) allowed[i][i] = true;
        for (auto &p : jumps) {
            if (p.size() < 2) continue;
            char from = p[0], to = p[1];
            if ('a' <= from && from <= 'z' && 'a' <= to && to <= 'z')
                allowed[from - 'a'][to - 'a'] = true;
        }

        // prefix sums
        vector<long long> prefTotal(n + 1, 0);
        vector<vector<long long>> prefChar(ALPHA, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; ++i) {
            prefTotal[i + 1] = prefTotal[i] + a[i];
            for (int c = 0; c < ALPHA; ++c) prefChar[c][i + 1] = prefChar[c][i];
            int ci = a[i] - 'a';
            if (0 <= ci && ci < ALPHA) prefChar[ci][i + 1] += a[i];
        }

        const long long NEG = LLONG_MIN / 4;
        vector<long long> bestTo(ALPHA, NEG);
        vector<long long> dp(n, NEG);

        dp[0] = 0;
        for (int t = 0; t < ALPHA; ++t)
            if (allowed[a[0] - 'a'][t])
                bestTo[t] = max(bestTo[t], dp[0] - prefTotal[0] + prefChar[t][0]);

        long long ans = 0;
        for (int j = 1; j < n; ++j) {
            int t = a[j] - 'a';
            if (0 <= t && t < ALPHA && bestTo[t] != NEG) {
                long long cand = bestTo[t] + (prefTotal[j] - prefChar[t][j]);
                dp[j] = cand;
                ans = max(ans, cand);
            }
            if (dp[j] != NEG) {
                for (int trg = 0; trg < ALPHA; ++trg)
                    if (allowed[a[j] - 'a'][trg]) {
                        long long v = dp[j] - prefTotal[j] + prefChar[trg][j];
                        bestTo[trg] = max(bestTo[trg], v);
                    }
            }
        }

        return (int) ans;
    }
};
