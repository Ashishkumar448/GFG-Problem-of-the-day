class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        n, m = len(s1), len(s2)
        min_len = float("inf")
        start_index = -1

        i = 0
        while i < n:
            j = 0

            # Move forward to match s2
            while i < n:
                if s1[i] == s2[j]:
                    j += 1
                    if j == m:
                        break
                i += 1

            if i == n:
                break

            end = i
            j = m - 1

            # Shrink window backward
            while i >= 0:
                if s1[i] == s2[j]:
                    j -= 1
                    if j < 0:
                        break
                i -= 1

            start = i
            window_len = end - start + 1

            if window_len < min_len:
                min_len = window_len
                start_index = start

            i = start + 1

        return "" if start_index == -1 else s1[start_index:start_index + min_len]
