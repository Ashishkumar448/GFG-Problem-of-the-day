# { Driver Code Starts
# Initial Template for Python

class Solution:
    def minIncrements(self, arr):
        # Sort the array first
        arr.sort()
        
        # Initialize increment count
        increments = 0
        
        # Iterate through the sorted array
        for i in range(1, len(arr)):
            # If the current element is not greater than the previous element,
            # increment it to make it unique
            if arr[i] <= arr[i - 1]:
                required_increment = arr[i - 1] + 1 - arr[i]
                arr[i] = arr[i - 1] + 1 # Update the current element
                increments += required_increment
        
        return increments

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        result = obj.minIncrements(arr)
        print(result)
# } Driver Code Ends

