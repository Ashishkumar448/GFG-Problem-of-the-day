class Solution:
    def pythagoreanTriplet(self, arr):
        # Square all elements
        arr = [x * x for x in arr]
        
        # Store squares in a set
        squares = set(arr)
        
        n = len(arr)
        # Check for all pairs
        for i in range(n):
            for j in range(i + 1, n):
                if arr[i] + arr[j] in squares:
                    return True
        return False
