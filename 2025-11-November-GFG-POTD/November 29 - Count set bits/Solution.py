class Solution:
    @staticmethod
    def largestPowerOf2(n):
        x = 0
        while (1 << (x + 1)) <= n:
            x += 1
        return x

    @staticmethod
    def countSetBits(n):
        count = 0

        while n > 0:
            x = Solution.largestPowerOf2(n)

            # full cycles
            count += x * (1 << (x - 1))

            # remaining numbers
            count += n - (1 << x) + 1

            n -= (1 << x)

        return count
