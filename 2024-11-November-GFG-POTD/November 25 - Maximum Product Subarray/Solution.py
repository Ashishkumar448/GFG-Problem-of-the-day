class Solution:
    # Function to find maximum product subarray
    def maxProduct(self, arr):
        n = len(arr)
        
        # Initialize the maximum and minimum product ending at the current position
        currentMax = arr[0]
        currentMin = arr[0]
        
        # Initialize the result with the first element
        maxProduct = arr[0]
        
        # Traverse through the array from the second element
        for i in range(1, n):
            temp = currentMax
            
            # Update currentMax and currentMin based on the current element
            currentMax = max(arr[i], max(currentMax * arr[i], currentMin * arr[i]))
            currentMin = min(arr[i], min(temp * arr[i], currentMin * arr[i]))
            
            # Update the result with the maximum product so far
            maxProduct = max(maxProduct, currentMax)
        
        return maxProduct

# Driver code
if __name__ == "__main__":
    tc = int(input())  # Number of test cases
    for _ in range(tc):
        arr = list(map(int, input().split()))
        obj = Solution()
        print(obj.maxProduct(arr))
