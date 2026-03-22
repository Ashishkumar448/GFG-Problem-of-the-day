class Solution {
    public int orangesRot(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        
        // Step 1: Add all rotten oranges & count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.offer(new int[]{i, j});
                } else if (mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // If no fresh oranges
        if (fresh == 0) return 0;
        
        int time = 0;
        int[][] dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Step 2: BFS
        while (!q.isEmpty()) {
            int size = q.size();
            boolean rottenThisRound = false;
            
            for (int i = 0; i < size; i++) {
                int[] curr = q.poll();
                
                for (int[] d : dirs) {
                    int ni = curr[0] + d[0];
                    int nj = curr[1] + d[1];
                    
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && mat[ni][nj] == 1) {
                        mat[ni][nj] = 2;
                        q.offer(new int[]{ni, nj});
                        fresh--;
                        rottenThisRound = true;
                    }
                }
            }
            
            // Increase time only if rotting happened
            if (rottenThisRound) time++;
        }
        
        // Step 3: Check if all fresh are rotten
        return (fresh == 0) ? time : -1;
    }
}
