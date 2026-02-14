class Solution:
    def minTime(self, arr, k):
        def isPossible(maxTime):
            painters = 1
            currentTime = 0

            for length in arr:
                if currentTime + length <= maxTime:
                    currentTime += length
                else:
                    painters += 1
                    currentTime = length

                    if painters > k:
                        return False
            return True

        low = max(arr)
        high = sum(arr)
        result = high

        while low <= high:
            mid = (low + high) // 2

            if isPossible(mid):
                result = mid
                high = mid - 1
            else:
                low = mid + 1

        return result
