class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        if (pa == pb) return;

        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pb] < rank[pa]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        // Not enough edges
        if ((int)edges.size() < V - 1) return -1;

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        // Union edges
        for (auto& e : edges) {
            unionSet(e[0], e[1], parent, rank);
        }

        // Count components
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (parent[i] == i) components++;
        }

        return components - 1;
    }
};
