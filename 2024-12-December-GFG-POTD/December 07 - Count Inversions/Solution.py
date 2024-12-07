class Solution:
    # Function to count inversions in the array.
    def inversionCount(self, arr):
        # Create a temporary array for merge sort.
        temp = [0] * len(arr)
        return self.mergeSortAndCount(arr, temp, 0, len(arr) - 1)

    # Function to implement merge sort and count inversions.
    def mergeSortAndCount(self, arr, temp, left, right):
        inversionCount = 0
        if left < right:
            # Find the middle point.
            mid = (left + right) // 2

            # Recursively count inversions in the left and right halves.
            inversionCount += self.mergeSortAndCount(arr, temp, left, mid)
            inversionCount += self.mergeSortAndCount(arr, temp, mid + 1, right)

            # Merge the two halves and count cross inversions.
            inversionCount += self.mergeAndCount(arr, temp, left, mid, right)
        return inversionCount

    # Function to merge two halves and count cross inversions.
    def mergeAndCount(self, arr, temp, left, mid, right):
        i = left       # Starting index for the left subarray.
        j = mid + 1    # Starting index for the right subarray.
        k = left       # Starting index to store sorted elements in temp.
        inversionCount = 0

        # Merge the two subarrays into temp[].
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                i += 1
            else:
                # Inversion found because arr[i] > arr[j].
                temp[k] = arr[j]
                j += 1
                inversionCount += (mid + 1 - i)  # Count all remaining elements in left subarray.
            k += 1

        # Copy remaining elements of the left subarray (if any).
        while i <= mid:
            temp[k] = arr[i]
            i += 1
            k += 1

        # Copy remaining elements of the right subarray (if any).
        while j <= right:
            temp[k] = arr[j]
            j += 1
            k += 1

        # Copy sorted elements back into the original array.
        for i in range(left, right + 1):
            arr[i] = temp[i]

        return inversionCount


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        sol = Solution()
        print(sol.inversionCount
