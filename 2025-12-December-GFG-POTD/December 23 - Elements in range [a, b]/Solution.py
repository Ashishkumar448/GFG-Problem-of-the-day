from bisect import bisect_left, bisect_right

class Solution:
    def cntInRange(self, arr, queries):
        result = []
        
        # Step 1: Sort the array
        arr.sort()
        
        # Step 2: Process each query
        for a, b in queries:
            left = bisect_left(arr, a)
            right = bisect_right(arr, b)
            result.append(right - left)
        
        return result
