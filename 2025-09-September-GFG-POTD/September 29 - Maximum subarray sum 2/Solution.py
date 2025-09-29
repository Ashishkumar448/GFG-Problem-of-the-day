from collections import deque

class Solution:
    def maxSubarrSum(self, arr, a: int, b: int) -> int:
        n = len(arr)

        # prefix sum
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + arr[i]

        dq = deque()
        ans = float('-inf')

        for r in range(a, n + 1):
            l = r - a

            # maintain increasing order of prefix values
            while dq and prefix[dq[-1]] >= prefix[l]:
                dq.pop()
            dq.append(l)

            # remove indices outside the [r-b, r-a] window
            while dq and dq[0] < r - b:
                dq.popleft()

            if dq:
                ans = max(ans, prefix[r] - prefix[dq[0]])

        return int(ans)
