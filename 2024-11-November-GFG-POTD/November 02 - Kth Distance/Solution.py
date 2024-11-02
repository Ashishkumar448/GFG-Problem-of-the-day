class Solution:
    def checkDuplicatesWithinK(self, arr, k):
        # Set to keep track of elements within the current window of size k
        seen = set()

        # Traverse the array
        for i in range(len(arr)):
            # If the element already exists in the set, a duplicate within k distance is found
            if arr[i] in seen:
                return True

            # Add the current element to the set
            seen.add(arr[i])

            # Ensure the size of the set is within the window of size k
            if i >= k:
                seen.remove(arr[i - k])

        # If no duplicates are found within the distance of k
        return False


# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        
        obj = Solution()
        result = obj.checkDuplicatesWithinK(arr, k)
        print("true" if result else "false")
        print("~")
