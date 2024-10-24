class Solution:
    def modifyAndRearrangeArr(self, arr):
        # Step 1: Modify the array by merging adjacent duplicate elements
        for i in range(len(arr) - 1):
            if arr[i] == arr[i + 1] and arr[i] != 0:
                arr[i] = arr[i] * 2  # Merge duplicates
                arr[i + 1] = 0       # Set next element to 0

        # Step 2: Rearrange the array by moving all zeroes to the end
        result = []
        zero_count = 0

        # Add non-zero elements to the result list
        for num in arr:
            if num != 0:
                result.append(num)
            else:
                zero_count += 1

        # Append the zeroes at the end of the result list
        result.extend([0] * zero_count)

        return result

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        array1 = list(map(int, input().split()))
        sol = Solution()
        result = sol.modifyAndRearrangeArr(array1)
        print(" ".join(map(str, result)))
