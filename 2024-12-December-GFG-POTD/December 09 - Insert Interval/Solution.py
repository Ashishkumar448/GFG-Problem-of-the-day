class Solution:
    def insertInterval(self, intervals, newInterval):
        result = []
        i, n = 0, len(intervals)

        # Add all intervals that come before the new interval
        while i < n and intervals[i][1] < newInterval[0]:
            result.append(intervals[i])
            i += 1

        # Merge overlapping intervals
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        result.append(newInterval)

        # Add all intervals that come after the new interval
        while i < n:
            result.append(intervals[i])
            i += 1

        return result


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        intervals = [list(map(int, input().split())) for _ in range(n)]
        newInterval = list(map(int, input().split()))
        obj = Solution()
        ans = obj.insertInterval(intervals, newInterval)
        print("[", end="")
        for i in range(len(ans)):
            print(f"[{ans[i][0]},{ans[i][1]}]", end="")
            if i != len(ans) - 1:
                print(",", end="")
        print("]")
