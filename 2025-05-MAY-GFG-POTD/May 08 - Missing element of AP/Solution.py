class Solution:
    def findMissing(self, arr):
        n = len(arr)
        d = (arr[-1] - arr[0]) // n

        for i in range(n - 1):
            if arr[i + 1] - arr[i] != d:
                return arr[i] + d

        # If no missing element, return the next element in AP
        return arr[-1] + d
