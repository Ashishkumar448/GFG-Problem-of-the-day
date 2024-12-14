class Solution:
    def peakElement(self, arr):
        n = len(arr)
        # Handle edge cases
        if n == 1:
            return 0

        # Check for peak elements at the beginning and end
        if arr[0] > arr[1]:
            return 0
        if arr[n - 1] > arr[n - 2]:
            return n - 1

        # Iterate through the array from index 1 to n-2
        for i in range(1, n - 1):
            if arr[i] > arr[i + 1] and arr[i] > arr[i - 1]:
                return i

        return -1  # No peak element found

def main():
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        idx = obj.peakElement(arr)
        n = len(arr)
        f = False

        if idx < 0 or idx >= n:
            print("false")
        else:
            if n == 1 and idx == 0:
                f = True
            elif idx == 0 and arr[0] > arr[1]:
                f = True
            elif idx == n - 1 and arr[n - 1] > arr[n - 2]:
                f = True
            elif idx > 0 and idx < n and arr[idx] > arr[idx + 1] and arr[idx] > arr[idx - 1]:
                f = True
            print("true" if f else "false")
        print("~")

if __name__ == "__main__":
    main()
