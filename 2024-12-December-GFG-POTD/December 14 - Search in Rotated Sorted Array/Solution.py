class Solution:
    def search(self, arr, key):
        low, high = 0, len(arr) - 1

        while low <= high:
            mid = low + (high - low) // 2

            # Check if the middle element is the key
            if arr[mid] == key:
                return mid

            # Check which part is sorted
            if arr[low] <= arr[mid]:
                # Left part is sorted
                if key >= arr[low] and key < arr[mid]:
                    high = mid - 1  # Key lies in the left part
                else:
                    low = mid + 1  # Key lies in the right part
            else:
                # Right part is sorted
                if key > arr[mid] and key <= arr[high]:
                    low = mid + 1  # Key lies in the right part
                else:
                    high = mid - 1  # Key lies in the left part

        # Key not found
        return -1


if __name__ == "__main__":
    t = int(input().strip())
    ob = Solution()

    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        key = int(input().strip())
        print(ob.search(arr, key))
        print("~")
