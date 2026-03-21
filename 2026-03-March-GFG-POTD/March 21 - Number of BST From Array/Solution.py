class Solution:
    def countBSTs(self, arr):
        n = len(arr)
        
        # Step 1: Precompute Catalan numbers
        catalan = [0] * (n + 1)
        catalan[0] = 1
        if n >= 1:
            catalan[1] = 1
        
        for i in range(2, n + 1):
            for j in range(i):
                catalan[i] += catalan[j] * catalan[i - j - 1]
        
        result = []
        
        # Step 2: Compute answer for each root
        for i in range(n):
            root = arr[i]
            leftCount = 0
            rightCount = 0
            
            for j in range(n):
                if arr[j] < root:
                    leftCount += 1
                elif arr[j] > root:
                    rightCount += 1
            
            result.append(catalan[leftCount] * catalan[rightCount])
        
        return result
