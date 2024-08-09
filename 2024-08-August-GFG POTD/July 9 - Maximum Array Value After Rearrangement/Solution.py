class Solution:
    def Maximize(self, arr):
        # Sort the array in ascending order
        arr.sort()

        # Initialize the result to store the maximum value
        result = 0

        # Define a modulus value to prevent integer overflow
        mod = 1000000007

        # Iterate through the array and calculate the maximum sum
        for i in range(len(arr)):
            result = (result + arr[i] * i) % mod

        # Return the result
        return result


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        sol = Solution()
        print(sol.Maximize(arr))
