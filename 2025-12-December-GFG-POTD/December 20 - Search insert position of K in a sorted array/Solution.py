class Solution:
    def searchInsertK(self, arr, k):
        low, high = 0, len(arr) - 1

        while low <= high:
            mid = low + (high - low) // 2

            if arr[mid] == k:
                return mid
            elif arr[mid] < k:
                low = mid + 1
            else:
                high = mid - 1

        # low is the insertion position
        return low
