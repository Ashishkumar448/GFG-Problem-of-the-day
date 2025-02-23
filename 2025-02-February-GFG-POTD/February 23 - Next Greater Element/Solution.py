class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        result = [-1] * n
        stack = []

        for i in range(n - 1, -1, -1):
            while stack and stack[-1] <= arr[i]:
                stack.pop()
            if stack:
                result[i] = stack[-1]
            stack.append(arr[i])

        return result


if __name__ == "__main__":
    t = int(input().strip())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        obj = Solution()
        res = obj.nextLargerElement(arr)
        print(" ".join(map(str, res)))
        print("~")
