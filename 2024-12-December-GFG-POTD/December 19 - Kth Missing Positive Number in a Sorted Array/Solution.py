class Solution:
    def kthMissing(self, arr, k):
        missing_count = 0  # Counts missing numbers
        current = 1        # Start from the smallest positive number
        index = 0          # Tracks position in the array

        while True:
            if index < len(arr) and arr[index] == current:
                # Current number is in the array, move to the next number
                index += 1
            else:
                # Current number is missing
                missing_count += 1
                if missing_count == k:
                    return current  # Found the kth missing number
            current += 1


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input().strip())

        sol = Solution()
        result = sol.kthMissing(arr, k)

        print(result)
        print("~")

