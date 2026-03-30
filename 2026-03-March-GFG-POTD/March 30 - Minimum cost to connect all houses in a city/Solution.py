class Solution:
    def minCost(self, houses):
        n = len(houses)
        
        visited = [False] * n
        minDist = [float('inf')] * n
        
        minDist[0] = 0
        result = 0
        
        for _ in range(n):
            u = -1
            
            # Pick minimum distance unvisited node
            for j in range(n):
                if not visited[j] and (u == -1 or minDist[j] < minDist[u]):
                    u = j
            
            visited[u] = True
            result += minDist[u]
            
            # Update distances
            for v in range(n):
                if not visited[v]:
                    dist = abs(houses[u][0] - houses[v][0]) + \
                           abs(houses[u][1] - houses[v][1])
                    
                    if dist < minDist[v]:
                        minDist[v] = dist
        
        return result
