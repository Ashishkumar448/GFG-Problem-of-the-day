class Solution:
    def maxMinHeight(self, arr, k, w):
        def isPossible(arr, k, w, target):
            n = len(arr)
            water = [0] * (n + 1)
            opsUsed = 0
            curWater = 0

            for i in range(n):
                curWater += water[i]
                currentHeight = arr[i] + curWater
                if currentHeight < target:
                    delta = target - currentHeight
                    opsUsed += delta
                    if opsUsed > k:
                        return False
                    curWater += delta
                    if i + w < n:
                        water[i + w] -= delta
            return True

        low = min(arr)
        high = low + k
        answer = low

        while low <= high:
            mid = (low + high) // 2
            if isPossible(arr, k, w, mid):
                answer = mid
                low = mid + 1
            else:
                high = mid - 1

        return answer
