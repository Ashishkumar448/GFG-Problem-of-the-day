class Solution:
    # Function to count the number of subarrays which adds to the given sum.
    def subArraySum(self, arr, tar):
        # Dictionary to store the frequency of prefix sums
        prefixSumMap = {}
        count = 0
        prefixSum = 0

        # To account for the case when the subarray starts from index 0
        prefixSumMap[0] = 1

        # Traverse through the array
        for num in arr:
            # Calculate the running prefix sum
            prefixSum += num

            # Check if prefixSum - target exists in the map
            if prefixSum - tar in prefixSumMap:
                # If yes, add the count of occurrences of (prefixSum - target) to the result
                count += prefixSumMap[prefixSum - tar]

            # Update the frequency of the current prefix sum in the map
            prefixSumMap[prefixSum] = prefixSumMap.get(prefixSum, 0) + 1

        return count

# Driver code
if __name__ == "__main__":
    t = int(input())

    while t > 0:
        t -= 1
        line = input().strip()

        # Split the line into integers
        arr = list(map(int, line.split()))

        tar = int(input())

        obj = Solution()
        res = obj.subArraySum(arr, tar)

        print(res)
