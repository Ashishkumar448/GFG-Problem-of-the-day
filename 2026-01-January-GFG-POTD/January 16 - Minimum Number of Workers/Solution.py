class Solution:
    def minMen(self, arr):
        n = len(arr)
        intervals = []

        # Build intervals
        for i in range(n):
            if arr[i] != -1:
                left = max(0, i - arr[i])
                right = min(n - 1, i + arr[i])
                intervals.append((left, right))

        # Sort intervals
        intervals.sort(key=lambda x: (x[0], -x[1]))

        workers = 0
        curr = 0
        i = 0

        # Greedy coverage
        while curr < n:
            farthest = curr

            while i < len(intervals) and intervals[i][0] <= curr:
                farthest = max(farthest, intervals[i][1] + 1)
                i += 1

            if farthest == curr:
                return -1  # cannot extend coverage

            workers += 1
            curr = farthest

        return workers
