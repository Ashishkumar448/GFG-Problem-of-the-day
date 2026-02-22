class Solution:
    def subarrayXor(self, arr, k):
        from collections import defaultdict
        
        mp = defaultdict(int)
        
        count = 0
        xr = 0
        
        # Base case: prefix XOR 0 appears once
        mp[0] = 1
        
        for num in arr:
            xr ^= num
            
            # If (xr ^ k) exists, add its frequency
            count += mp[xr ^ k]
            
            # Update frequency of current prefix xor
            mp[xr] += 1
        
        return count
