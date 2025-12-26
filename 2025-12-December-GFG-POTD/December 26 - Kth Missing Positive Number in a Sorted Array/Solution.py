class Solution:
    def kthMissing(self, arr, k):
        low, high = 0, len(arr) - 1
        
        while low <= high:
            mid = low + (high - low) // 2
            
            # Count of missing numbers till index mid
            missing = arr[mid] - (mid + 1)
            
            if missing < k:
                low = mid + 1
            else:
                high = mid - 1
        
        # kth missing number
        return low + k
