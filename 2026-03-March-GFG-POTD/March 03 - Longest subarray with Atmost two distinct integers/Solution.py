class Solution:
    def totalElements(self, arr):
        left = 0
        max_length = 0
        freq = {}
        
        for right in range(len(arr)):
            # Add current element
            freq[arr[right]] = freq.get(arr[right], 0) + 1
            
            # Shrink window if more than 2 distinct elements
            while len(freq) > 2:
                freq[arr[left]] -= 1
                
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                
                left += 1
            
            # Update maximum length
            max_length = max(max_length, right - left + 1)
        
        return max_length
