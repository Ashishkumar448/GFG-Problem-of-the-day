#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // build graph
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        if ((int)order.size() != n) return {}; // cycle detected
        return order;
    }
};
