class Solution:
    def circularSubarraySum(self, arr):
        n = len(arr)
        
        # Step 1: Find the maximum sum of a normal subarray using Kadane's Algorithm
        max_normal = self.kadane(arr)
        
        # If all elements are negative, max_normal will be the answer
        if max_normal < 0:
            return max_normal
        
        # Step 2: Calculate the total sum of the array
        total_sum = sum(arr)
        
        # Step 3: Find the minimum sum of a normal subarray
        # To get the minimum sum, invert the sign of all elements and apply Kadane's Algorithm
        inverted_arr = [-x for x in arr]
        max_inverted = self.kadane(inverted_arr)
        
        # Step 4: Calculate the circular sum and return the maximum
        max_circular = total_sum + max_inverted  # Since we inverted the signs, max_inverted gives -minSum
        
        return max(max_normal, max_circular)
    
    # Kadane's algorithm to find the maximum subarray sum
    def kadane(self, arr):
        max_ending_here = max_so_far = arr[0]
        
        for i in range(1, len(arr)):
            max_ending_here = max(arr[i], max_ending_here + arr[i])
            max_so_far = max(max_so_far, max_ending_here)
        
        return max_so_far

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        print(Solution().circularSubarraySum(arr))
