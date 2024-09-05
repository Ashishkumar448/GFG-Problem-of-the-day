class Solution:
    def missingNumber(self, n, arr):
        # Calculate the expected sum of the first n natural numbers
        total_sum = n * (n + 1) // 2

        # Calculate the sum of elements in the array
        current_sum = sum(arr)

        # The missing number is the difference
        return total_sum - current_sum

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        sln = Solution()
        print(sln.missingNumber(n, arr))
