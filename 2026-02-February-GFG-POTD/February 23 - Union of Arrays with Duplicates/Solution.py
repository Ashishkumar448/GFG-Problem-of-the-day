class Solution:
    def findUnion(self, a, b):
        s = set()
        
        # Add elements of array a
        for num in a:
            s.add(num)
        
        # Add elements of array b
        for num in b:
            s.add(num)
        
        return list(s)
