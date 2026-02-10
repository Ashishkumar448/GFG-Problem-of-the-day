class Solution:
    def kokoEat(self, arr, k):
        low, high = 1, max(arr)
        answer = high

        while low <= high:
            mid = low + (high - low) // 2

            if self.canFinish(arr, k, mid):
                answer = mid      # try smaller speed
                high = mid - 1
            else:
                low = mid + 1     # need higher speed

        return answer

    def canFinish(self, arr, k, speed):
        hours = 0

        for bananas in arr:
            hours += (bananas + speed - 1) // speed  # ceil division
            if hours > k:
                return False

        return True
