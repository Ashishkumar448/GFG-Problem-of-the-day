class Solution:
    def minDaysBloom(self, arr, k, m):
        n = len(arr)
        
        # If not enough flowers
        if m * k > n:
            return -1
        
        left, right = min(arr), max(arr)
        ans = -1
        
        while left <= right:
            mid = (left + right) // 2
            if self.canMake(arr, k, m, mid):
                ans = mid
                right = mid - 1  # try smaller
            else:
                left = mid + 1  # need more days
        return ans
    
    def canMake(self, arr, k, m, day):
        count = 0
        bouquets = 0
        for bloom in arr:
            if bloom <= day:
                count += 1
                if count == k:
                    bouquets += 1
                    count = 0
            else:
                count = 0
            if bouquets >= m:
                return True
        return False
