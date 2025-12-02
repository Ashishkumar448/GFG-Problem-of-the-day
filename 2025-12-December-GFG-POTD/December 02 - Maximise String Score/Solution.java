class Solution {
    public int maxScore(String s, char[][] jumps) {
        if (s == null || s.length() == 0) return 0;
        final int ALPHA = 26;
        int n = s.length();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = s.charAt(i);

        // build adjacency: allowed[c][t] = true if can jump from char c -> t (or c == t allowed)
        boolean[][] allowed = new boolean[ALPHA][ALPHA];
        for (int i = 0; i < ALPHA; ++i) allowed[i][i] = true; // same-character jumps always allowed
        for (char[] p : jumps) {
            if (p == null || p.length < 2) continue;
            char from = p[0], to = p[1];
            if (from < 'a' || from > 'z' || to < 'a' || to > 'z') continue; // adjust if needed
            allowed[from - 'a'][to - 'a'] = true;
        }

        // prefix sums
        long[] prefTotal = new long[n + 1];
        long[][] prefChar = new long[ALPHA][n + 1];

        for (int i = 0; i < n; ++i) {
            prefTotal[i + 1] = prefTotal[i] + a[i];
            // copy previous column for each char then add current if matches
            for (int c = 0; c < ALPHA; ++c) {
                prefChar[c][i + 1] = prefChar[c][i];
            }
            int ci = a[i] - 'a';
            if (0 <= ci && ci < ALPHA) prefChar[ci][i + 1] += a[i];
        }

        final long NEG = Long.MIN_VALUE / 4;
        long[] bestTo = new long[ALPHA]; // bestTo[t] as derived
        for (int t = 0; t < ALPHA; ++t) bestTo[t] = NEG;

        long[] dp = new long[n];
        for (int i = 0; i < n; ++i) dp[i] = NEG;

        // start at index 0
        dp[0] = 0;
        // update bestTo entries using index 0
        for (int t = 0; t < ALPHA; ++t) {
            if (allowed[a[0] - 'a'][t]) {
                // dp[0] - prefTotal[0] + prefChar[t][0]  (both prefTotal[0], prefChar[*][0] are 0)
                bestTo[t] = Math.max(bestTo[t], dp[0] - prefTotal[0] + prefChar[t][0]);
            }
        }

        long ans = 0; // max dp over reachable indices
        for (int j = 1; j < n; ++j) {
            int t = a[j] - 'a';
            if (t < 0 || t >= ALPHA) continue; // safety
            if (bestTo[t] != NEG) {
                long cand = bestTo[t] + (prefTotal[j] - prefChar[t][j]);
                dp[j] = cand;
                if (cand > ans) ans = cand;
            }
            // After computing dp[j] (or leaving it NEG), update bestTo for targets reachable from s[j]
            if (dp[j] != NEG) {
                for (int trg = 0; trg < ALPHA; ++trg) {
                    if (allowed[a[j] - 'a'][trg]) {
                        long val = dp[j] - prefTotal[j] + prefChar[trg][j];
                        if (val > bestTo[trg]) bestTo[trg] = val;
                    }
                }
            }
        }

        // answer is maximum dp value; dp[0] = 0 may be best but jumps yield positive sums typically
        return (int) ans;
    }
}
