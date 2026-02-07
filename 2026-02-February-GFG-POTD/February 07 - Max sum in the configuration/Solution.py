class Solution:
    def maxSum(self, arr):
        n = len(arr)
        
        arrSum = 0
        currVal = 0
        
        # Step 1 & 2: calculate total sum and initial value
        for i in range(n):
            arrSum += arr[i]
            currVal += i * arr[i]
        
        maxVal = currVal
        
        # Step 3: compute values for other rotations
        for i in range(1, n):
            currVal = currVal + arrSum - n * arr[n - i]
            maxVal = max(maxVal, currVal)
        
        return maxVal
