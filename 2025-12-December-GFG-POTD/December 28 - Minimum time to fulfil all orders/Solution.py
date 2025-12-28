class Solution:
    def minTime(self, ranks, n):
        minRank = min(ranks)

        low = 0
        high = minRank * n * (n + 1) // 2
        ans = high

        while low <= high:
            mid = low + (high - low) // 2

            if self.canMake(ranks, n, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans

    def canMake(self, ranks, n, time):
        donuts = 0

        for r in ranks:
            k = 0
            currTime = 0

            while True:
                currTime += r * (k + 1)
                if currTime > time:
                    break
                k += 1

            donuts += k
            if donuts >= n:
                return True

        return False
