class Solution:
    def cntWays(self, arr):
        n = len(arr)
        
        totalEven = 0
        totalOdd = 0
        
        # Step 1: total sums
        for i in range(n):
            if i % 2 == 0:
                totalEven += arr[i]
            else:
                totalOdd += arr[i]
        
        leftEven = 0
        leftOdd = 0
        count = 0
        
        # Step 2: try removing each index
        for i in range(n):
            rightEven = totalEven - leftEven
            rightOdd = totalOdd - leftOdd
            
            if i % 2 == 0:
                rightEven -= arr[i]
            else:
                rightOdd -= arr[i]
            
            # After removal, indices on right swap parity
            newEvenSum = leftEven + rightOdd
            newOddSum = leftOdd + rightEven
            
            if newEvenSum == newOddSum:
                count += 1
            
            # Update prefix sums
            if i % 2 == 0:
                leftEven += arr[i]
            else:
                leftOdd += arr[i]
        
        return count
