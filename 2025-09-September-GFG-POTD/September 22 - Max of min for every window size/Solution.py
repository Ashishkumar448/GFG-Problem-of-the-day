from collections import deque

class Solution:
    def maxOfMins(self, arr):
        n = len(arr)
        left = [-1] * n
        right = [n] * n

        dq = deque()

        # Previous Smaller Element
        for i in range(n):
            while dq and arr[dq[-1]] >= arr[i]:
                dq.pop()
            if dq:
                left[i] = dq[-1]
            dq.append(i)

        dq.clear()

        # Next Smaller Element
        for i in range(n - 1, -1, -1):
            while dq and arr[dq[-1]] >= arr[i]:
                dq.pop()
            if dq:
                right[i] = dq[-1]
            dq.append(i)

        ans = [0] * (n + 1)

        # Fill contributions
        for i in range(n):
            length = right[i] - left[i] - 1
            ans[length] = max(ans[length], arr[i])

        # Propagate values
        for i in range(n - 1, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])

        return ans[1:]
