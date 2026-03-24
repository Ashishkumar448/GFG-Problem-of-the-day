#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        // Step 1: Build graph
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Queue for nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process nodes
        int count = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Check
        return count == n;
    }
};
