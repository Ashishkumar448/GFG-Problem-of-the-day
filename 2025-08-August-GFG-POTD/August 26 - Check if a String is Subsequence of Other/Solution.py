class Solution:
    def isSubSeq(self, s1: str, s2: str) -> bool:
        i, j = 0, 0
        n, m = len(s1), len(s2)

        while i < n and j < m:
            if s1[i] == s2[j]:
                i += 1
            j += 1

        return i == n  # true if all chars of s1 matched in order
