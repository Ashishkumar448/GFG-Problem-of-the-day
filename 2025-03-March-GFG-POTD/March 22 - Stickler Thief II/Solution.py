class Solution:
    def maxValue(self, arr):
        n = len(arr)
        if n == 1:
            return arr[0]
        if n == 2:
            return max(arr[0], arr[1])

        return max(self.rob(arr[:-1]), self.rob(arr[1:]))

    def rob(self, arr):
        prev2, prev1 = 0, 0
        for num in arr:
            curr = max(prev1, prev2 + num)
            prev2, prev1 = prev1, curr
        return prev1


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        res = obj.maxValue(arr)
        print(res)
        print("~")
