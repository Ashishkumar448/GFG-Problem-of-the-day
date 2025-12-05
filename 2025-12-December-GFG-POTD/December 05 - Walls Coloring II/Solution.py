class Solution:
    def minCost(self, costs):
        n = len(costs)
        if n == 0:
            return 0
        k = len(costs[0])

        if k == 1:
            return costs[0][0] if n == 1 else -1

        min1 = 0
        min2 = 0
        idx1 = -1

        for i in range(n):
            newMin1 = float('inf')
            newMin2 = float('inf')
            newIdx1 = -1

            for j in range(k):
                currCost = costs[i][j]

                if j == idx1:
                    currCost += min2
                else:
                    currCost += min1

                if currCost < newMin1:
                    newMin2 = newMin1
                    newMin1 = currCost
                    newIdx1 = j
                elif currCost < newMin2:
                    newMin2 = currCost

            min1 = newMin1
            min2 = newMin2
            idx1 = newIdx1

        return min1
