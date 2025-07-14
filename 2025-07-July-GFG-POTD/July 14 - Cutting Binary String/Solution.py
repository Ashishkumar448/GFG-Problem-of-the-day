class Solution:
    def cuts(self, s: str) -> int:
        n = len(s)
        power_of_5 = set()

        # Generate all powers of 5 in binary up to 2^30
        num = 1
        while num <= (1 << 30):
            power_of_5.add(bin(num)[2:])
            num *= 5

        dp = [float('inf')] * (n + 1)
        dp[0] = 0  # base case

        for i in range(1, n + 1):
            for j in range(i - 1, -1, -1):
                sub = s[j:i]
                if sub[0] == '0':
                    continue
                if sub in power_of_5 and dp[j] != float('inf'):
                    dp[i] = min(dp[i], dp[j] + 1)

        return -1 if dp[n] == float('inf') else dp[n]
