class Solution:
    def countAtMostK(self, arr, k):
        if k == 0:
            return 0
        
        from collections import defaultdict
        freq = defaultdict(int)
        
        left = 0
        count = 0
        
        for right in range(len(arr)):
            freq[arr[right]] += 1
            
            while len(freq) > k:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1
            
            count += (right - left + 1)
        
        return count
