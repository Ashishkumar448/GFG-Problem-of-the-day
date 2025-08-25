class Solution:
    # check if we can make the median at least 'target' using at most 'k' operations
    def isPossible(self, arr, target, k):
        n = len(arr)

        if n % 2 == 1:
            # odd-sized array → consider elements from middle to end
            for i in range(n // 2, n):
                if arr[i] < target:
                    k -= (target - arr[i])
                if k < 0:
                    break
        else:
            # even-sized array → handle two middle elements separately
            if arr[n // 2] <= target:
                k -= (target - arr[n // 2])
                k -= (target - arr[n // 2 - 1])
            else:
                k -= (2 * target - (arr[n // 2] + arr[n // 2 - 1]))
            
            # process remaining elements to the right
            for i in range(n // 2 + 1, n):
                if arr[i] < target:
                    k -= (target - arr[i])
                if k < 0:
                    break
        
        return k >= 0

    def maximizeMedian(self, arr, k):
        n = len(arr)
        arr.sort()

        # compute initial median (floor if even length)
        iniMedian = arr[n // 2]
        if n % 2 == 0:
            iniMedian += arr[n // 2 - 1]
            iniMedian //= 2

        low, high = iniMedian, iniMedian + k
        bestMedian = iniMedian

        # binary search to find maximum achievable median
        while low <= high:
            mid = (low + high) // 2
            if self.isPossible(arr, mid, k):
                bestMedian = mid
                low = mid + 1
            else:
                high = mid - 1

        return bestMedian
