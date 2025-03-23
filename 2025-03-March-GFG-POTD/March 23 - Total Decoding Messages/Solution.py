class Solution:
    def countWays(self, digits: str) -> int:
        if not digits or digits[0] == '0':
            return 0

        n = len(digits)
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1

        for i in range(2, n + 1):
            # Check single digit
            if digits[i - 1] != '0':
                dp[i] += dp[i - 1]

            # Check two digits
            two_digits = int(digits[i - 2:i])
            if 10 <= two_digits <= 26:
                dp[i] += dp[i - 2]

        return dp[n]


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        digits = input().strip()
        ob = Solution()
        ans = ob.countWays(digits)
        print(ans)
        print("~")

