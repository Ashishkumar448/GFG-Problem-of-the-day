class Solution:
    def equalSumSpan(self, a1, a2):
        n = len(a1)
        
        mp = {0: -1}   # diff 0 at index -1
        prefix1 = 0
        prefix2 = 0
        maxLen = 0
        
        for i in range(n):
            prefix1 += a1[i]
            prefix2 += a2[i]
            
            diff = prefix1 - prefix2
            
            if diff in mp:
                maxLen = max(maxLen, i - mp[diff])
            else:
                mp[diff] = i   # store first occurrence
        
        return maxLen
