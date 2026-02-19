class Solution:
    def missingRange(self, arr, low, high):
        result = []
        s = set(arr)   # Store array elements in set
        
        # Check for missing numbers in range
        for i in range(low, high + 1):
            if i not in s:
                result.append(i)
        
        return result
