class Solution:
    def maxProfit(self, jobs):
        # Sort jobs by end time
        jobs.sort(key=lambda x: x[1])
        n = len(jobs)
        dp = [0] * n
        dp[0] = jobs[0][2]

        for i in range(1, n):
            include_profit = jobs[i][2]
            
            # Find last non-conflicting job using binary search
            l = self.find_last_non_conflict(jobs, i)
            if l != -1:
                include_profit += dp[l]
            
            dp[i] = max(dp[i - 1], include_profit)
        
        return dp[-1]

    def find_last_non_conflict(self, jobs, i):
        low, high = 0, i - 1
        while low <= high:
            mid = (low + high) // 2
            if jobs[mid][1] <= jobs[i][0]:
                if mid + 1 < i and jobs[mid + 1][1] <= jobs[i][0]:
                    low = mid + 1
                else:
                    return mid
            else:
                high = mid - 1
        return -1
