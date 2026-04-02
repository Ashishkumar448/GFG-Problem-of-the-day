class Solution:
    def countWays(self, n, k):
        if n == 1:
            return k

        same = k              # for n = 2
        diff = k * (k - 1)    # for n = 2

        for i in range(3, n + 1):
            newSame = diff
            newDiff = (same + diff) * (k - 1)

            same = newSame
            diff = newDiff

        return same + diff
