from collections import deque

class Solution:
    def minCostPath(self, mat):
        n, m = len(mat), len(mat[0])
        
        low, high = 0, 1_000_000
        ans = 0
        
        while low <= high:
            mid = (low + high) // 2
            
            if self.canReach(mat, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans

    def canReach(self, mat, maxDiff):
        n, m = len(mat), len(mat[0])
        vis = [[False] * m for _ in range(n)]
        
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        
        q = deque()
        q.append((0, 0))
        vis[0][0] = True
        
        while q:
            x, y = q.popleft()
            
            if x == n - 1 and y == m - 1:
                return True
            
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                
                if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
                    if abs(mat[x][y] - mat[nx][ny]) <= maxDiff:
                        vis[nx][ny] = True
                        q.append((nx, ny))
        
        return False
