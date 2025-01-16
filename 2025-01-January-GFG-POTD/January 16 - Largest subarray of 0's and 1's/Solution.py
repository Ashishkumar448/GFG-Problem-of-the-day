class Solution:
    def maxLen(self, arr):
        # Map to store the first occurrence of a prefix sum
        prefix_map = {}
        max_length = 0  # Stores the maximum length of subarray
        cum_sum = 0     # Tracks the cumulative sum
        
        for i in range(len(arr)):
            # Treat 0 as -1 for the purpose of summing
            cum_sum += -1 if arr[i] == 0 else 1
            
            if cum_sum == 0:
                # If sum is 0, subarray from start to current index has equal 0's and 1's
                max_length = i + 1
            
            # If this sum has been seen before
            if cum_sum in prefix_map:
                # Calculate the length of the subarray
                max_length = max(max_length, i - prefix_map[cum_sum])
            else:
                # Store the first occurrence of this sum
                prefix_map[cum_sum] = i
        
        return max_length

# Driver code
if __name__ == "__main__":
    T = int(input())  # Read number of test cases
    for _ in range(T):
        arr = list(map(int, input().split()))  # Read the array
        obj = Solution()
        print(obj.maxLen(arr))
