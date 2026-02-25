class Solution:
    def longestSubarray(self, arr, k):
        prefix_sum = 0
        max_len = 0
        mp = {}
        
        for i in range(len(arr)):
            # Convert to +1 / -1
            if arr[i] > k:
                prefix_sum += 1
            else:
                prefix_sum -= 1
            
            # If prefix sum > 0, whole array till i is valid
            if prefix_sum > 0:
                max_len = i + 1
            else:
                # Check if prefix_sum - 1 exists
                if (prefix_sum - 1) in mp:
                    max_len = max(max_len, i - mp[prefix_sum - 1])
            
            # Store first occurrence only
            if prefix_sum not in mp:
                mp[prefix_sum] = i
        
        return max_len
