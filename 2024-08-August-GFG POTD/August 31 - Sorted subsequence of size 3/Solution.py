# { Driver Code Starts

class Solution:
    # Function to find three numbers such that arr[leftMin[i]] < arr[i] < arr[rightMax[i]]
    def find3Numbers(self, arr):
        n = len(arr)
        result = []

        if n < 3:
            return result  # If less than 3 elements, no subsequence of size 3 exists.

        # Arrays to store the index of the smallest element to the left and the largest element to the right
        leftMin = [-1] * n
        rightMax = [-1] * n

        minIndex = 0

        # Fill the leftMin array
        for i in range(1, n):
            if arr[i] <= arr[minIndex]:
                minIndex = i
            else:
                leftMin[i] = minIndex

        maxIndex = n - 1

        # Fill the rightMax array
        for i in range(n - 2, -1, -1):
            if arr[i] >= arr[maxIndex]:
                maxIndex = i
            else:
                rightMax[i] = maxIndex

        # Find the subsequence of size 3
        for i in range(1, n - 1):
            if leftMin[i] != -1 and rightMax[i] != -1:
                result.append(arr[leftMin[i]])
                result.append(arr[i])
                result.append(arr[rightMax[i]])
                return result  # Return the first found subsequence

        return result  # No subsequence found


# Function to check if v2 is a subsequence of v1
def isSubSequence(v1, v2):
    m = len(v2)
    n = len(v1)
    j = 0  # For index of v2

    # Traverse v1 and v2
    for i in range(n):
        if j < m and v1[i] == v2[j]:
            j += 1

    return j == m


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        res = obj.find3Numbers(arr)
        if len(res) != 0 and len(res) != 3:
            print(-1)
        else:
            if len(res) == 0:
                print(0)
            elif res[0] < res[1] < res[2] and isSubSequence(arr, res):
                print(1)
            else:
                print(-1)
# } Driver Code Ends
