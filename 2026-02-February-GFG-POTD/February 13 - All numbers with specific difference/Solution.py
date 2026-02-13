class Solution:
    
    def digitSum(self, num: int) -> int:
        s = 0
        while num > 0:
            s += num % 10
            num //= 10
        return s
    
    def getCount(self, n: int, d: int) -> int:
        low, high = 1, n
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            
            if mid - self.digitSum(mid) >= d:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        if ans == -1:
            return 0
        
        return n - ans + 1
