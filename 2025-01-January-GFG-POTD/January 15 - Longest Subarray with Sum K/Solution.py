class Solution:
    def longestSubarray(self, arr, k):
        prefix_sum_map = {}  # Dictionary to store prefix sums and their indices
        prefix_sum = 0
        max_length = 0

        # Iterate through the array
        for i, num in enumerate(arr):
            prefix_sum += num  # Update prefix sum

            # Check if prefix_sum equals k
            if prefix_sum == k:
                max_length = i + 1  # Update max_length for the entire array up to this point

            # Check if (prefix_sum - k) exists in the map
            if prefix_sum - k in prefix_sum_map:
                # Calculate the length of the subarray and update max_length
                max_length = max(max_length, i - prefix_sum_map[prefix_sum - k])

            # Store prefix_sum in the map if not already present
            if prefix_sum not in prefix_sum_map:
                prefix_sum_map[prefix_sum] = i

        return max_length


# Driver code
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))  # Read the array input
        k = int(input())  # Read target sum

        ob = Solution()
        ans = ob.longestSubarray(arr, k)
        print(ans)
        print("~")
