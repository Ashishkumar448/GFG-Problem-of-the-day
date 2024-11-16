class Solution:
    def pushZerosToEnd(self, arr):
        n = len(arr)
        index = 0  # Index to place the next non-zero element

        # Traverse the array and move non-zero elements to the front
        for i in range(n):
            if arr[i] != 0:
                arr[index] = arr[i]
                index += 1

        # Fill the rest of the array with zeros
        while index < n:
            arr[index] = 0
            index += 1

if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        arr = list(map(int, input().split()))
        Solution().pushZerosToEnd(arr)
        print(" ".join(map(str, arr)))
