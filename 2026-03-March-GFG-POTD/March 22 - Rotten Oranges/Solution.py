from collections import deque

class Solution:
    def orangesRot(self, mat):
        n, m = len(mat), len(mat[0])
        
        q = deque()
        fresh = 0
        
        # Step 1: Add rotten & count fresh
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2:
                    q.append((i, j))
                elif mat[i][j] == 1:
                    fresh += 1
        
        if fresh == 0:
            return 0
        
        time = 0
        dirs = [(-1,0), (1,0), (0,-1), (0,1)]
        
        # Step 2: BFS
        while q:
            size = len(q)
            rotten_this_round = False
            
            for _ in range(size):
                x, y = q.popleft()
                
                for dx, dy in dirs:
                    ni, nj = x + dx, y + dy
                    
                    if 0 <= ni < n and 0 <= nj < m and mat[ni][nj] == 1:
                        mat[ni][nj] = 2
                        q.append((ni, nj))
                        fresh -= 1
                        rotten_this_round = True
            
            if rotten_this_round:
                time += 1
        
        return time if fresh == 0 else -1
