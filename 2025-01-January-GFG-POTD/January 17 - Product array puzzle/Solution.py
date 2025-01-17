class Solution:
    def productExceptSelf(self, arr):
        n = len(arr)
        left = [1] * n
        right = [1] * n
        res = [0] * n

        # Fill left product array
        for i in range(1, n):
            left[i] = left[i - 1] * arr[i - 1]

        # Fill right product array
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * arr[i + 1]

        # Construct the result array
        for i in range(n):
            res[i] = left[i] * right[i]

        return res


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.productExceptSelf(arr)
        print(" ".join(map(str, ans)))
        t -= 1
