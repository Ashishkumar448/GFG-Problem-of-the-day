from collections import deque

class Solution:
    def maxOfSubarrays(self, arr, k):
        result = []
        dq = deque()  # stores indices

        for i in range(len(arr)):

            # Remove indices out of current window
            while dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements from the back
            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            # Add current index
            dq.append(i)

            # Store max for the window
            if i >= k - 1:
                result.append(arr[dq[0]])

        return result
