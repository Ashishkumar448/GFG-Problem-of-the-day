class Solution:
    def activitySelection(self, start, finish):
        activities = sorted(zip(finish, start))  # Sort activities by finish time
        count = 1
        last_end_time = activities[0][0]

        for i in range(1, len(activities)):
            if activities[i][1] > last_end_time:
                count += 1
                last_end_time = activities[i][0]

        return count

if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        start = list(map(int, input().strip().split()))
        finish = list(map(int, input().strip().split()))

        obj = Solution()
        print(obj.activitySelection(start, finish))
        print("~")
