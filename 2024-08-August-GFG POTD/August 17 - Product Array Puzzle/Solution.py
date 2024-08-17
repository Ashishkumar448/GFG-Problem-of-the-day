class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        leftProduct = [0] * n
        rightProduct = [0] * n
        result = [0] * n

        # Initialize the first element of leftProduct as 1
        leftProduct[0] = 1
        for i in range(1, n):
            leftProduct[i] = nums[i - 1] * leftProduct[i - 1]

        # Initialize the last element of rightProduct as 1
        rightProduct[n - 1] = 1
        for i in range(n - 2, -1, -1):
            rightProduct[i] = nums[i + 1] * rightProduct[i + 1]

        # Multiply leftProduct and rightProduct to get the result
        for i in range(n):
            result[i] = leftProduct[i] * rightProduct[i]

        return result

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        array = list(map(int, input().split()))
        ob = Solution()
        ans = ob.productExceptSelf(array)
        print(" ".join(map(str, ans)))
