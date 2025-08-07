class Solution:
    def minDifference(self, arr):
        n = len(arr)
        seconds = []

        # Convert time strings to seconds
        for time_str in arr:
            h, m, s = map(int, time_str.split(":"))
            total_seconds = h * 3600 + m * 60 + s
            seconds.append(total_seconds)

        seconds.sort()
        min_diff = float('inf')

        # Compute difference between adjacent times
        for i in range(1, n):
            min_diff = min(min_diff, seconds[i] - seconds[i - 1])

        # Handle wrap-around at midnight
        day_in_seconds = 24 * 3600
        wrap_around_diff = day_in_seconds - seconds[-1] + seconds[0]
        min_diff = min(min_diff, wrap_around_diff)

        return min_diff
