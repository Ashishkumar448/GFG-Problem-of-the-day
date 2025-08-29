class Solution:
    @staticmethod
    def smallestWindow(s: str, p: str) -> str:
        if len(s) < len(p):
            return ""

        # frequency map for p
        freqP = [0] * 26
        for c in p:
            freqP[ord(c) - ord('a')] += 1

        freqS = [0] * 26
        count = 0
        required = len(p)

        min_len = float("inf")
        min_start = 0

        left = 0
        for right in range(len(s)):
            c = s[right]
            freqS[ord(c) - ord('a')] += 1

            if freqP[ord(c) - ord('a')] > 0 and freqS[ord(c) - ord('a')] <= freqP[ord(c) - ord('a')]:
                count += 1

            while count == required:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_start = left

                left_char = s[left]
                freqS[ord(left_char) - ord('a')] -= 1

                if freqP[ord(left_char) - ord('a')] > 0 and freqS[ord(left_char) - ord('a')] < freqP[ord(left_char) - ord('a')]:
                    count -= 1
                left += 1

        return "" if min_len == float("inf") else s[min_start:min_start + min_len]
