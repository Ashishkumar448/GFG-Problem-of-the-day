class Solution:
    @staticmethod
    def sumSubstrings(s: str) -> int:
        n = len(s)
        res = 0
        prev = 0

        for i in range(n):
            num = int(s[i])
            prev = prev * 10 + num * (i + 1)
            res += prev

        return res
