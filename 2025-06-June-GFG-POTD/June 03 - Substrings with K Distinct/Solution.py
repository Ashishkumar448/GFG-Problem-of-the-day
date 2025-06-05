class Solution:
    def countSubstr(self, s: str, k: int) -> int:
        return self.countAtMostK(s, k) - self.countAtMostK(s, k - 1)

    def countAtMostK(self, s: str, k: int) -> int:
        left = 0
        res = 0
        freq_map = {}

        for right in range(len(s)):
            freq_map[s[right]] = freq_map.get(s[right], 0) + 1

            while len(freq_map) > k:
                freq_map[s[left]] -= 1
                if freq_map[s[left]] == 0:
                    del freq_map[s[left]]
                left += 1

            res += right - left + 1

        return res
