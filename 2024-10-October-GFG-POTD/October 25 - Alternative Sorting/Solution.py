# Driver Code Starts
# Initial Template for Python

t = int(input())
for _ in range(t):
    array1 = list(map(int, input().split()))
    
    v = Solution().alternateSort(array1)
    
    print(" ".join(map(str, v)))
    print("~")

# } Driver Code Ends

# User function Template for Python

class Solution:
    def alternateSort(self, arr):
        # Sort the array
        arr.sort()

        result = []
        i = 0  # Pointer to the smallest element
        j = len(arr) - 1  # Pointer to the largest element

        while i <= j:
            # Append the largest element
            if i != j:
                result.append(arr[j])
                j -= 1

            # Append the smallest element
            result.append(arr[i])
            i += 1

        return result
