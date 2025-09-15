class Solution:
    def stringStack(self, pat: str, tar: str) -> bool:
        i = len(pat) - 1
        j = len(tar) - 1

        while i >= 0 and j >= 0:
            if pat[i] == tar[j]:
                # use pat[i] to match tar[j]
                i -= 1
                j -= 1
            else:
                # use pat[i] as delete -> skips previous appended char
                i -= 2

        return j < 0
