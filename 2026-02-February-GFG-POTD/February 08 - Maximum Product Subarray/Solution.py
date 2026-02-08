class Solution:
    def maxProduct(self, arr):
        maxEndingHere = arr[0]
        minEndingHere = arr[0]
        globalMax = arr[0]

        for i in range(1, len(arr)):
            curr = arr[i]

            # If current element is negative, swap max and min
            if curr < 0:
                maxEndingHere, minEndingHere = minEndingHere, maxEndingHere

            maxEndingHere = max(curr, maxEndingHere * curr)
            minEndingHere = min(curr, minEndingHere * curr)

            globalMax = max(globalMax, maxEndingHere)

        return globalMax
