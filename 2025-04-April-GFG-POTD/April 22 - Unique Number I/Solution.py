class Solution:
    def findUnique(self, arr):
        xor_result = 0
        for num in arr:
            xor_result ^= num
        return xor_result
