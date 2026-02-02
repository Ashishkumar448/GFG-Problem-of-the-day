class Solution:
    def maxCircularSum(self, arr):
        totalSum = arr[0]

        maxEndingHere = arr[0]
        maxSoFar = arr[0]

        minEndingHere = arr[0]
        minSoFar = arr[0]

        for i in range(1, len(arr)):
            x = arr[i]

            # Kadane for max subarray sum
            maxEndingHere = max(x, maxEndingHere + x)
            maxSoFar = max(maxSoFar, maxEndingHere)

            # Kadane for min subarray sum
            minEndingHere = min(x, minEndingHere + x)
            minSoFar = min(minSoFar, minEndingHere)

            totalSum += x

        # If all elements are negative
        if maxSoFar < 0:
            return maxSoFar

        # Maximum of wrapping and non-wrapping
        return max(maxSoFar, totalSum - minSoFar)
