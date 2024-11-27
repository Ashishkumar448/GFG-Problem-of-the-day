class Solution:
    # Function to find the smallest positive number missing from the array
    def missingNumber(self, arr):
        n = len(arr)

        # Step 1: Rearrange the array using cyclic sort
        for i in range(n):
            while 0 < arr[i] <= n and arr[arr[i] - 1] != arr[i]:
                # Swap arr[i] with the element at arr[arr[i] - 1]
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]

        # Step 2: Find the first index whose value is incorrect
        for i in range(n):
            if arr[i] != i + 1:
                return i + 1

        # If all elements are correctly placed, return n + 1
        return n + 1


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.missingNumber(arr)
        print(res)
