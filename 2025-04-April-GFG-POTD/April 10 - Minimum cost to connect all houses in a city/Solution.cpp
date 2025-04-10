#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            // Find the unvisited node with the minimum cost
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minCost[j] < minCost[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minCost[u];

            // Update cost of connecting other houses
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minCost[v] = min(minCost[v], dist);
                }
            }
        }

        return totalCost;
    }
};

// Example usage
int main() {
    Solution obj;
    vector<vector<int>> houses = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << obj.minCost(houses) << endl;  // Output: 105
    return 0;
}
