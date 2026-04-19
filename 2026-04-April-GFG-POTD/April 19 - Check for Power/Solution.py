class Solution:
    def isPower(self, x, y):
        # Edge case
        if x == 1:
            return y == 1

        # Keep dividing y by x if possible
        while y % x == 0:
            y //= x

        # If we reach 1, it's a power of x
        return y == 1
