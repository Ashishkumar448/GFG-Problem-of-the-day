class Solution:
    def divby13(self, s: str) -> bool:
        remainder = 0

        for c in s:
            digit = int(c)
            remainder = (remainder * 10 + digit) % 13

        return remainder == 0
