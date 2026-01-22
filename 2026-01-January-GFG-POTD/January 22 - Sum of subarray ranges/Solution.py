class Solution:
    def subarrayRanges(self, arr):
        sum_min = self.getSum(arr, True)
        sum_max = self.getSum(arr, False)
        return sum_max - sum_min

    def getSum(self, arr, isMin):
        n = len(arr)
        left = [0] * n
        right = [0] * n
        stack = []

        # Previous smaller / greater
        for i in range(n):
            while stack and (arr[stack[-1]] > arr[i] if isMin else arr[stack[-1]] < arr[i]):
                stack.pop()
            left[i] = i + 1 if not stack else i - stack[-1]
            stack.append(i)

        stack.clear()

        # Next smaller / greater
        for i in range(n - 1, -1, -1):
            while stack and (arr[stack[-1]] >= arr[i] if isMin else arr[stack[-1]] <= arr[i]):
                stack.pop()
            right[i] = n - i if not stack else stack[-1] - i
            stack.append(i)

        total = 0
        for i in range(n):
            total += arr[i] * left[i] * right[i]

        return total
