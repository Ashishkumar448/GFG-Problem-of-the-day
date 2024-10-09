# { Driver Code Starts
class Solution:
    def maxDistance(self, arr):
        # Create a dictionary to store the first occurrence of each element
        map = {}
        maxDist = 0

        # Traverse the array
        for i in range(len(arr)):
            if arr[i] in map:
                # Calculate the distance from the first occurrence
                dist = i - map[arr[i]]
                maxDist = max(maxDist, dist)  # Update the maximum distance
            else:
                # Store the index of the first occurrence
                map[arr[i]] = i

        return maxDist  # Return the maximum distance found


# { Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        input_data = input().strip()
        arr = list(map(int, input_data.split()))
        ob = Solution()
        print(ob.maxDistance(arr))
# } Driver Code Ends
