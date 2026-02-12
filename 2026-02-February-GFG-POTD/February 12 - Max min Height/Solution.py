class Solution:
    def maxMinHeight(self, arr, k, w):
        n = len(arr)
        
        low = min(arr)
        high = low + k
        ans = low
        
        while low <= high:
            mid = low + (high - low) // 2
            
            if self.canAchieve(arr, k, w, mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return ans
    
    def canAchieve(self, arr, k, w, target):
        n = len(arr)
        diff = [0] * (n + 1)
        added = 0
        used = 0
        
        for i in range(n):
            added += diff[i]
            currentHeight = arr[i] + added
            
            if currentHeight < target:
                need = target - currentHeight
                used += need
                
                if used > k:
                    return False
                
                added += need
                if i + w < len(diff):
                    diff[i + w] -= need
        
        return True
