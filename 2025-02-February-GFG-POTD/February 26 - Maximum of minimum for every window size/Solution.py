class Solution:
    def maxOfMins(self, arr):
        n = len(arr)
        left = [0] * n
        right = [0] * n
        result = [0] * (n + 1)
        stack = []

        # Finding previous smaller element
        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            left[i] = i + 1 if not stack else i - stack[-1]
            stack.append(i)

        # Clear stack for next calculation
        stack.clear()

        # Finding next smaller element
        for i in range(n - 1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            right[i] = (n - i) if not stack else (stack[-1] - i)
            stack.append(i)

        # Fill the result array based on window sizes
        for i in range(n):
            windowSize = left[i] + right[i] - 1
            result[windowSize] = max(result[windowSize], arr[i])

        # Fill remaining values to propagate the max values
        for i in range(n - 1, 0, -1):
            result[i] = max(result[i], result[i + 1])

        return result[1:]

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        result = solution.maxOfMins(arr)
        print(" ".join(map(str, result)))
        print("~")
