#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> graph(V);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> memo(V, -1);
        return dfs(src, dest, graph, memo);
    }

private:
    int dfs(int node, int dest, vector<vector<int>>& graph, vector<int>& memo) {
        if (node == dest) return 1;
        if (memo[node] != -1) return memo[node];

        int totalPaths = 0;
        for (int neighbor : graph[node]) {
            totalPaths += dfs(neighbor, dest, graph, memo);
        }

        memo[node] = totalPaths;
        return totalPaths;
    }
};
