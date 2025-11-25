class Solution:
    def subarrayXor(self, arr):
        n = len(arr)
        ans = 0

        if n % 2 == 1:
            for i in range(0, n, 2):
                ans ^= arr[i]

        return ans
