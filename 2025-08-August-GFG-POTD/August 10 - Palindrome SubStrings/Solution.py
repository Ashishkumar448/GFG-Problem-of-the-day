class Solution:
    def countPS(self, s: str) -> int:
        n = len(s)
        count = 0

        for center in range(n):
            count += self.expand_from_center(s, center, center)     # odd length
            count += self.expand_from_center(s, center, center + 1) # even length

        return count

    def expand_from_center(self, s: str, left: int, right: int) -> int:
        cnt = 0
        n = len(s)
        while left >= 0 and right < n and s[left] == s[right]:
            if right - left + 1 >= 2:
                cnt += 1
            left -= 1
            right += 1
        return cnt
