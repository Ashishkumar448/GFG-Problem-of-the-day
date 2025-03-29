class Solution:
    def jobSequencing(self, deadline, profit):
        n = len(deadline)
        jobs = sorted(zip(profit, deadline), reverse=True)  # Sort by profit (desc)

        max_deadline = max(deadline)
        slots = [False] * (max_deadline + 1)  # Track slot availability

        job_count = max_profit = 0
        for p, d in jobs:
            for j in range(d, 0, -1):  # Find latest available slot
                if not slots[j]:
                    slots[j] = True
                    job_count += 1
                    max_profit += p
                    break

        return [job_count, max_profit]

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        deadline = list(map(int, input().strip().split()))
        profit = list(map(int, input().strip().split()))

        obj = Solution()
        result = obj.jobSequencing(deadline, profit)
        print(result[0], result[1])
        print("~")
