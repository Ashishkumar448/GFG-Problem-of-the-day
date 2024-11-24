class Solution:
    # Function to find the sum of contiguous subarray with maximum sum.
    def maxSubarraySum(self, arr):
        max_sum = float('-inf')  # Initialize to the smallest possible value
        current_sum = 0

        for num in arr:
            current_sum += num
            max_sum = max(max_sum, current_sum)
            
            # If current_sum is negative, reset to 0
            if current_sum < 0:
                current_sum = 0
                
        return max_sum

# Driver code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        print(obj.maxSubarraySum(arr))
