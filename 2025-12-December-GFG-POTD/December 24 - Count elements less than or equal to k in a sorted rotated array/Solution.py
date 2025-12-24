class Solution:
    # Find pivot index (minimum element)
    def findPivot(self, arr):
        low, high = 0, len(arr) - 1

        while low < high:
            mid = low + (high - low) // 2
            if arr[mid] > arr[high]:
                low = mid + 1
            else:
                high = mid
        return low

    # Count elements <= x in sorted range [l..r]
    def countLE(self, arr, l, r, x):
        if l > r:
            return 0

        low, high = l, r
        res = l - 1

        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] <= x:
                res = mid
                low = mid + 1
            else:
                high = mid - 1

        return res - l + 1

    def countLessEqual(self, arr, x):
        n = len(arr)
        pivot = self.findPivot(arr)

        count = 0
        count += self.countLE(arr, pivot, n - 1, x)
        count += self.countLE(arr, 0, pivot - 1, x)

        return count
