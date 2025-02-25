class Solution:
    @staticmethod
    def getMaxArea(arr):
        n = len(arr)
        leftSmall = [-1] * n
        rightSmall = [n] * n
        stack = []

        # Find the first smaller bar on the left for each bar
        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                leftSmall[i] = stack[-1]
            stack.append(i)

        stack = []  # Clear the stack for reuse

        # Find the first smaller bar on the right for each bar
        for i in range(n - 1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                rightSmall[i] = stack[-1]
            stack.append(i)

        # Calculate the maximum area
        maxArea = 0
        for i in range(n):
            width = rightSmall[i] - leftSmall[i] - 1
            area = arr[i] * width
            maxArea = max(maxArea, area)

        return maxArea


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        res = Solution.getMaxArea(arr)
        print(res)
        print("~")
        t -= 1
