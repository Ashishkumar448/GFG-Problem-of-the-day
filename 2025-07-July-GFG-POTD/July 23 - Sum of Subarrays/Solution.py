class Solution:
    def subarraySum(self, arr):
        n = len(arr)
        totalSum = 0

        for i in range(n):
            totalSum += arr[i] * (i + 1) * (n - i)

        return totalSum
