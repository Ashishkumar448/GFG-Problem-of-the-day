class Solution:
    def longestKSubstr(self, s, k):
        freq = [0] * 26
        left = 0
        right = 0
        distinct = 0
        max_len = -1

        while right < len(s):
            idx = ord(s[right]) - ord('a')

            if freq[idx] == 0:
                distinct += 1

            freq[idx] += 1

            while distinct > k:
                left_idx = ord(s[left]) - ord('a')
                freq[left_idx] -= 1

                if freq[left_idx] == 0:
                    distinct -= 1

                left += 1

            if distinct == k:
                max_len = max(max_len, right - left + 1)

            right += 1

        return max_len
