class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        if n == 0:
            return 0
        if n == 1:
            return cost[0]

        prev2, prev1 = cost[0], cost[1]

        for i in range(2, n):
            curr = cost[i] + min(prev1, prev2)
            prev2 = prev1
            prev1 = curr

        return min(prev1, prev2)


if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        cost = list(map(int, input().split()))
        obj = Solution()
        print(obj.minCostClimbingStairs(cost))
        print("~")
