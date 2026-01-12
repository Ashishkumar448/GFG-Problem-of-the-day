from collections import deque

class Solution:
    def maxOfSubarrays(self, arr, k):
        dq = deque()
        result = []

        for i in range(len(arr)):

            # Remove indices out of window
            while dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements
            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            # Add current index
            dq.append(i)

            # Append max once window is complete
            if i >= k - 1:
                result.append(arr[dq[0]])

        return result
