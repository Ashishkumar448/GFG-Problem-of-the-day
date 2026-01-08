class Solution:
    def countSubarrays(self, arr, k):
        return self.atMost(arr, k) - self.atMost(arr, k - 1)
    
    def atMost(self, arr, k):
        left = 0
        count = 0
        odds = 0
        
        for right in range(len(arr)):
            if arr[right] % 2 != 0:
                odds += 1
            
            while odds > k:
                if arr[left] % 2 != 0:
                    odds -= 1
                left += 1
            
            count += (right - left + 1)
        
        return count
