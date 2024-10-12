class Solution:
    def pairWithMaxSum(self, arr):
        n = len(arr)
        if n < 2:
            return -1
        max_sum = arr[0] + arr[1]
        for i in range(1, n - 1):
            max_sum = max(max_sum, arr[i] + arr[i + 1])
        return max_sum


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        res = obj.pairWithMaxSum(arr)
        print(res)
