class Solution:
    def sort012(self, arr):
        low = 0        # Pointer for 0s
        mid = 0        # Pointer for 1s
        high = len(arr) - 1  # Pointer for 2s

        while mid <= high:
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1
            elif arr[mid] == 1:
                mid += 1
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1

# Driver code
if __name__ == "__main__":
    t = int(input())  # Number of test cases

    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ob.sort012(arr)
        print(*arr)  # Print sorted array
