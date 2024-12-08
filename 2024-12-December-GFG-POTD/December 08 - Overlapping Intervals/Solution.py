class Solution:
    def mergeOverlap(self, intervals):
        # Step 1: Sort the intervals by the start time
        intervals.sort(key=lambda x: x[0])

        merged = []
        current_interval = intervals[0]
        merged.append(current_interval)

        for interval in intervals:
            current_start, current_end = current_interval
            next_start, next_end = interval

            # If intervals overlap, merge them
            if current_end >= next_start:
                current_interval[1] = max(current_end, next_end)
            else:
                # If they don't overlap, move to the next interval
                current_interval = interval
                merged.append(current_interval)

        return merged


# Driver Code
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        arr = [list(map(int, input().split())) for _ in range(n)]
        obj = Solution()
        ans = obj.mergeOverlap(arr)

        for interval in ans:
            print(interval[0], interval[1], end=" ")
        print()
