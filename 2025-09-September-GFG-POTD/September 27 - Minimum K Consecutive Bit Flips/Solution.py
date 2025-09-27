class Solution:
    def kBitFlips(self, arr, k: int) -> int:
        n = len(arr)
        res = 0
        flipCount = 0
        isFlipped = [0] * n  # to track when a flip effect ends

        for i in range(n):
            if i >= k:
                flipCount ^= isFlipped[i - k]  # remove expired flip

            if (arr[i] ^ flipCount) == 0:  # need to flip
                if i + k > n:
                    return -1
                res += 1
                flipCount ^= 1  # start new flip
                isFlipped[i] = 1  # mark flip start

        return res
