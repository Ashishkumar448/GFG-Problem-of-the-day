import bisect

class Solution:
    def minimumCoins(self, arr, k):
        arr.sort()
        n = len(arr)

        # Prefix sum
        prefixSum = [0] * (n + 1)
        for i in range(n):
            prefixSum[i + 1] = prefixSum[i] + arr[i]

        minCoins = float('inf')

        for i in range(n):
            minVal = arr[i]
            maxAllowed = minVal + k

            # bisect_right gives the first index where arr[j] > maxAllowed
            j = bisect.bisect_right(arr, maxAllowed) - 1

            leftRemove = prefixSum[i]

            totalRightCoins = prefixSum[n] - prefixSum[j + 1]
            countRight = n - j - 1
            maxAllowedTotal = countRight * maxAllowed
            rightRemove = totalRightCoins - maxAllowedTotal

            totalRemove = leftRemove + rightRemove
            minCoins = min(minCoins, totalRemove)

        return minCoins
