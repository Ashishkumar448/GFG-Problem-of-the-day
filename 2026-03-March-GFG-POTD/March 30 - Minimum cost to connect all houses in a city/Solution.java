

class Solution {

    public int minCost(int[][] houses) {
        int n = houses.length;
        
        boolean[] visited = new boolean[n];
        int[] minDist = new int[n];
        
        // Initialize distances with infinity
        for (int i = 0; i < n; i++) {
            minDist[i] = Integer.MAX_VALUE;
        }
        
        // Start from first house
        minDist[0] = 0;
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            int u = -1;
            
            // Pick minimum distance unvisited node
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            visited[u] = true;
            result += minDist[u];
            
            // Update distances
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = Math.abs(houses[u][0] - houses[v][0]) +
                               Math.abs(houses[u][1] - houses[v][1]);
                    
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }
        
        return result;
    }
    
}
