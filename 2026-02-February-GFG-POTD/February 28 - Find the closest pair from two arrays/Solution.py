class Solution:
    def findClosestPair(self, arr1, arr2, x):
        n = len(arr1)
        m = len(arr2)
        
        i = 0
        j = m - 1
        
        min_diff = float('inf')
        res1 = res2 = 0
        
        while i < n and j >= 0:
            s = arr1[i] + arr2[j]
            diff = abs(s - x)
            
            if diff < min_diff:
                min_diff = diff
                res1 = arr1[i]
                res2 = arr2[j]
            
            if s > x:
                j -= 1
            else:
                i += 1
        
        return [res1, res2]
