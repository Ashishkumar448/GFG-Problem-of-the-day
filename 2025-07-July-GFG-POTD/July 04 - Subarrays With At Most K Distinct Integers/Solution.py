from collections import defaultdict

class Solution:
    def countAtMostK(self, arr, k):
        freq_map = defaultdict(int)
        start = 0
        result = 0
        
        for end in range(len(arr)):
            freq_map[arr[end]] += 1
            
            while len(freq_map) > k:
                freq_map[arr[start]] -= 1
                if freq_map[arr[start]] == 0:
                    del freq_map[arr[start]]
                start += 1
                
            result += end - start + 1
        
        return result
