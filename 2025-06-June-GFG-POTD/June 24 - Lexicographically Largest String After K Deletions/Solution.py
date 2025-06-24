class Solution:
    def maxSubseq(self, s: str, k: int) -> str:
        res = []
        for char in s:
            while k > 0 and res and res[-1] < char:
                res.pop()
                k -= 1
            res.append(char)
        if k > 0:
            res = res[:-k]
        return ''.join(res)
