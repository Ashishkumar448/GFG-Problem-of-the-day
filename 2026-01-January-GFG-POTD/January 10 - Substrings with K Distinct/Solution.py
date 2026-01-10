class Solution:
    def countSubstr(self, s: str, k: int) -> int:
        def atMostK(s, k):
            if k < 0:
                return 0
            freq = [0] * 26
            left = 0
            distinct = 0
            count = 0

            for right in range(len(s)):
                r = ord(s[right]) - ord('a')
                if freq[r] == 0:
                    distinct += 1
                freq[r] += 1

                while distinct > k:
                    l = ord(s[left]) - ord('a')
                    freq[l] -= 1
                    if freq[l] == 0:
                        distinct -= 1
                    left += 1

                count += right - left + 1
            return count

        return atMostK(s, k) - atMostK(s, k - 1)
