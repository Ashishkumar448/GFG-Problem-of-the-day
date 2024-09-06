# Function to find the sum of contiguous subarray with maximum sum.
def maxSubarraySum(arr):
    max_sum = float('-inf')  # Initialize maxSum to the smallest possible integer value
    current_sum = 0          # Initialize currentSum to 0

    # Iterate through the array
    for num in arr:
        current_sum += num          # Add the current element to currentSum
        max_sum = max(max_sum, current_sum)  # Update maxSum if currentSum is greater

        if current_sum < 0:  # Reset currentSum to 0 if it drops below 0
            current_sum = 0

    return max_sum  # Return the maximum sum found

# Driver code
if __name__ == "__main__":
    t = int(input())  # Inputting the testcases
    for _ in range(t):
        arr = list(map(int, input().split()))  # Read the array elements
        print(maxSubarraySum(arr))  # Calling maxSubarraySum function
