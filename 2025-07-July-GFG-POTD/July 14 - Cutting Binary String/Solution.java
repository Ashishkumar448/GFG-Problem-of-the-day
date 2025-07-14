class Solution {
    public int cuts(String s) {
        int n = s.length();
        Set<String> powerOf5 = new HashSet<>();

        // Generate all powers of 5 in binary up to 2^30
        long num = 1;
        while (num <= (1L << 30)) {
            powerOf5.add(Long.toBinaryString(num));
            num *= 5;
        }

        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0; // base case

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                String sub = s.substring(j, i);
                if (sub.charAt(0) == '0') continue; // skip leading zeros
                if (powerOf5.contains(sub)) {
                    if (dp[j] != Integer.MAX_VALUE)
                        dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] == Integer.MAX_VALUE ? -1 : dp[n];
    }
}
