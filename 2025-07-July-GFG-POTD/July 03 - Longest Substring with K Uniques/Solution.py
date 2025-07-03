class Solution:
    def longestKSubstr(self, s: str, k: int) -> int:
        n = len(s)
        if n == 0 or k == 0:
            return -1

        freq = {}
        max_length = -1
        start = 0

        for end in range(n):
            char = s[end]
            freq[char] = freq.get(char, 0) + 1

            while len(freq) > k:
                left_char = s[start]
                freq[left_char] -= 1
                if freq[left_char] == 0:
                    del freq[left_char]
                start += 1

            if len(freq) == k:
                max_length = max(max_length, end - start + 1)

        return max_length
