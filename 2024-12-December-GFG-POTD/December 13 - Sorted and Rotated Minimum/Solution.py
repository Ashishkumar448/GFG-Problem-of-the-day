class Solution:
    def findMin(self, arr):
        low, high = 0, len(arr) - 1

        # Binary search for the minimum element
        while low < high:
            mid = low + (high - low) // 2

            # If mid element is greater than the high element, the min is in the right half
            if arr[mid] > arr[high]:
                low = mid + 1
            # Else, the min is in the left half (including mid)
            else:
                high = mid

        # At the end, low == high, pointing to the minimum element
        return arr[low]


if __name__ == "__main__":
    t = int(input().strip())
    ob = Solution()

    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        print(ob.findMin(arr))
        print("~")
