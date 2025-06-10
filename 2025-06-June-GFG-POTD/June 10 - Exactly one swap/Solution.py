class Solution:
    def countStrings(self, s: str) -> int:
        m = [0] * 26
        ans = 0
        for i in range(len(s)):
            ans += i - m[ord(s[i]) - ord('a')]
            m[ord(s[i]) - ord('a')] += 1
        for x in m:
            if x > 1:
                ans += 1
                break
        return ans
