class Solution:
    def minRemoval(self, intervals):
        # Sort intervals based on their end times
        intervals.sort(key=lambda x: x[1])

        count = 0  # Count of intervals to remove
        prevEnd = float('-inf')  # End of the last added interval

        for interval in intervals:
            # If the current interval starts before the previous one ends, overlap occurs
            if interval[0] < prevEnd:
                count += 1
            else:
                # Update the end to the current interval's end
                prevEnd = interval[1]

        return count


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        intervals = [list(map(int, input().split())) for _ in range(n)]
        obj = Solution()
        ans = obj.minRemoval(intervals)
        print(ans)
