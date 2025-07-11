class Solution {
     public int countConsec(int n) {
        int[] dp0 = new int[n + 1]; // ending with 0
        int[] dp1 = new int[n + 1]; // ending with 1

        // Base cases
        dp0[1] = 1; // "0"
        dp1[1] = 1; // "1"

        for (int i = 2; i <= n; i++) {
            dp0[i] = dp0[i - 1] + dp1[i - 1];
            dp1[i] = dp0[i - 1];
        }

        int total = 1 << n; // 2^n
        int nonConsec = dp0[n] + dp1[n];

        return total - nonConsec;
    }
}
