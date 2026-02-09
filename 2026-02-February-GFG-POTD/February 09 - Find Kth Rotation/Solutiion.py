class Solution:
    def findKRotation(self, arr):
        low, high = 0, len(arr) - 1
        n = len(arr)

        while low <= high:
            # If subarray is already sorted
            if arr[low] <= arr[high]:
                return low

            mid = low + (high - low) // 2
            prev = (mid - 1 + n) % n
            next = (mid + 1) % n

            # Check if mid is minimum
            if arr[mid] <= arr[prev] and arr[mid] <= arr[next]:
                return mid

            # Decide which half to search
            if arr[mid] >= arr[low]:
                # Left half sorted → go right
                low = mid + 1
            else:
                # Right half sorted → go left
                high = mid - 1

        return 0
