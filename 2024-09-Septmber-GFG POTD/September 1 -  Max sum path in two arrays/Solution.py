# { Driver Code Starts
class Solution:
    def maxPathSum(self, arr1, arr2):
        i, j = 0, 0
        sum1, sum2 = 0, 0
        result = 0

        # Traverse both arrays
        while i < len(arr1) and j < len(arr2):
            if arr1[i] < arr2[j]:
                sum1 += arr1[i]
                i += 1
            elif arr1[i] > arr2[j]:
                sum2 += arr2[j]
                j += 1
            else:
                # Both arrays have the same value at i and j
                result += max(sum1, sum2) + arr1[i]
                sum1 = 0
                sum2 = 0
                i += 1
                j += 1

        # Add remaining elements of arr1
        while i < len(arr1):
            sum1 += arr1[i]
            i += 1

        # Add remaining elements of arr2
        while j < len(arr2):
            sum2 += arr2[j]
            j += 1

        # Add the maximum of the remaining sums to the result
        result += max(sum1, sum2)

        return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr1 = list(map(int, input().split()))
        arr2 = list(map(int, input().split()))

        ob = Solution()
        ans = ob.maxPathSum(arr1, arr2)
        print(ans)
# } Driver Code Ends
