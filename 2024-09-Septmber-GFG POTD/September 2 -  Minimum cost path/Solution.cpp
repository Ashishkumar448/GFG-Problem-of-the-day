#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the minimum cost to reach the bottom-right cell from the top-left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Priority queue to store cells based on their cost.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        
        // Directions for moving up, down, left, right.
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int cost = current[0], x = current[1], y = current[2];
            
            // If we reached the bottom-right corner, return the cost.
            if (x == n - 1 && y == n - 1) {
                return cost;
            }
            
            // Explore all four possible directions.
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the new position is within the grid boundaries.
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newCost = cost + grid[nx][ny];
                    
                    // Update the distance if a shorter path is found.
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << endl;
    }
    return 0;
}
