class Solution:
    def computeLPSArray(self, s, lps):
        length = 0
        idx = 1
        lps[0] = 0

        while idx < len(s):
            if s[idx] == s[length]:
                length += 1
                lps[idx] = length
                idx += 1
            else:
                if length == 0:
                    lps[idx] = 0
                    idx += 1
                else:
                    length = lps[length - 1]

    def KMPSearch(self, txt, pat, lps, rep):
        n, m = len(txt), len(pat)
        i, j = 0, 0

        while i < n * rep:
            if txt[i % n] == pat[j]:
                i += 1
                j += 1
                if j == m:
                    return True
            else:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False

    def minRepeats(self, s1, s2):
        n, m = len(s1), len(s2)
        lps = [0] * m
        self.computeLPSArray(s2, lps)

        x = (m + n - 1) // n

        if self.KMPSearch(s1, s2, lps, x):
            return x
        if self.KMPSearch(s1, s2, lps, x + 1):
            return x + 1

        return -1


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        A = input().strip()
        B = input().strip()
        ob = Solution()
        print(ob.minRepeats(A, B))
