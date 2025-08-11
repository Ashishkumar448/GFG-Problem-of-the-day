

class Solution:
    def maxSum(self, s: str) -> int:
        n = len(s)
        left = [1] * n
        right = [1] * n
        rad = [0] * n

        # Manacher's algorithm for odd-length palindromes
        l, r = 0, -1
        for i in range(n):
            k = 1 if i > r else min(rad[l + r - i], r - i + 1)
            while i - k >= 0 and i + k < n and s[i - k] == s[i + k]:
                k += 1
            rad[i] = k
            k -= 1
            if i + k > r:
                l = i - k
                r = i + k

        # Fill left[]
        for i in range(n):
            length = rad[i] * 2 - 1
            end = i + rad[i] - 1
            if end < n:
                left[end] = max(left[end], length)
        for i in range(n - 2, -1, -1):
            left[i] = max(left[i], left[i + 1] - 2)
        for i in range(1, n):
            left[i] = max(left[i], left[i - 1])

        # Fill right[]
        for i in range(n - 1, -1, -1):
            length = rad[i] * 2 - 1
            start = i - rad[i] + 1
            if start >= 0:
                right[start] = max(right[start], length)
        for i in range(1, n):
            right[i] = max(right[i], right[i - 1] - 2)
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i], right[i + 1])

        ans = 1
        for i in range(n - 1):
            ans = max(ans, left[i] + right[i + 1])
        return ans
