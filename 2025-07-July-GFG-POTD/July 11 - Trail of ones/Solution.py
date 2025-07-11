class Solution:
    def countConsec(self, n: int) -> int:
        dp0 = [0] * (n + 1)  # ending with 0
        dp1 = [0] * (n + 1)  # ending with 1

        # Base cases
        dp0[1] = 1  # "0"
        dp1[1] = 1  # "1"

        for i in range(2, n + 1):
            dp0[i] = dp0[i - 1] + dp1[i - 1]
            dp1[i] = dp0[i - 1]

        total = 1 << n  # 2^n
        nonConsec = dp0[n] + dp1[n]

        return total - nonConsec
