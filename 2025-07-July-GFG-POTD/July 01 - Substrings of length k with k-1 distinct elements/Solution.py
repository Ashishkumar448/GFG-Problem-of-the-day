from collections import defaultdict

class Solution:
    def substrCount(self, s: str, k: int) -> int:
        if len(s) < k:
            return 0

        freq = defaultdict(int)
        count = 0

        # First window
        for i in range(k):
            freq[s[i]] += 1
        if len(freq) == k - 1:
            count += 1

        # Slide window
        for i in range(k, len(s)):
            out_char = s[i - k]
            freq[out_char] -= 1
            if freq[out_char] == 0:
                del freq[out_char]

            in_char = s[i]
            freq[in_char] += 1

            if len(freq) == k - 1:
                count += 1

        return count
