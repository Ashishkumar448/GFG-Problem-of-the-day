class Solution {
public:

    // DSU Structure
    struct DSU {
        vector<int> p, r;
        DSU(int n) {
            p.resize(n);
            r.assign(n, 0);
            for (int i = 0; i < n; i++) p[i] = i;
        }
        int find(int x) {
            return (p[x] == x) ? x : (p[x] = find(p[x]));
        }
        bool unite(int a, int b) {
            a = find(a); 
            b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) p[a] = b;
            else if (r[b] < r[a]) p[b] = a;
            else { p[b] = a; r[a]++; }
            return true;
        }
    };

    // Build MST skipping one specific edge
    int buildMST(int V, vector<vector<int>>& edges, int su, int sv, int sw) {
        DSU d(V);
        int sum = 0, used = 0;

        for (auto &e : edges) {
            if (e[0] == su && e[1] == sv && e[2] == sw) continue;
            if (d.unite(e[0], e[1])) {
                sum += e[2];
                used++;
            }
        }

        return (used == V - 1 ? sum : INT_MAX);
    }

    int secondMST(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        int mstWeight = buildMST(V, edges, -1, -1, -1);
        if (mstWeight == INT_MAX) return -1;

        int secondBest = INT_MAX;

        for (auto &e : edges) {
            int w = buildMST(V, edges, e[0], e[1], e[2]);
            if (w > mstWeight) secondBest = min(secondBest, w);
        }

        return (secondBest == INT_MAX ? -1 : secondBest);
    }
};
