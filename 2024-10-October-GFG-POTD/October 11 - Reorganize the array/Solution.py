class Solution:
    def rearrange(self, arr):
        n = len(arr)
        result = [-1] * n
        for i in range(n):
            value = arr[i]
            if value >= 0 and value < n:
                result[value] = value
        return result


if __name__ == "__main__":
    t = int(input())
    solution = Solution()

    for _ in range(t):
        arr = list(map(int, input().split()))
        ans = solution.rearrange(arr)
        print(" ".join(map(str, ans)))
