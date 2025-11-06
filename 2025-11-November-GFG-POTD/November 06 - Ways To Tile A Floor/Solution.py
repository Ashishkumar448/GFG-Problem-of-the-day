class Solution:
    def numberOfWays(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        a, b = 1, 2
        for _ in range(3, n + 1):
            c = a + b
            a, b = b, c
        return c
