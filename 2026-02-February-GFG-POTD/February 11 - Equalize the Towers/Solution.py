class Solution:
    def calculateCost(self, heights, cost, target):
        total = 0
        
        for i in range(len(heights)):
            total += abs(heights[i] - target) * cost[i]
        
        return total
    
    def minCost(self, heights, cost):
        low = min(heights)
        high = max(heights)
        
        answer = float('inf')
        
        while low <= high:
            mid = low + (high - low) // 2
            
            cost1 = self.calculateCost(heights, cost, mid)
            cost2 = self.calculateCost(heights, cost, mid + 1)
            
            answer = min(cost1, cost2)
            
            if cost1 < cost2:
                high = mid - 1
            else:
                low = mid + 1
        
        return answer
