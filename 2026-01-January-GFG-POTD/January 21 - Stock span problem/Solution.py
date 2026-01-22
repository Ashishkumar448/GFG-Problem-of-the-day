class Solution:
    def calculateSpan(self, arr):
        span = []
        stack = []

        for i in range(len(arr)):

            # Pop while current price is higher or equal
            while stack and arr[stack[-1]] <= arr[i]:
                stack.pop()

            curr_span = i + 1 if not stack else i - stack[-1]
            span.append(curr_span)

            # Push current index
            stack.append(i)

        return span
