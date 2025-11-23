class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unionSet(int x, int y) {
            int px = find(x);
            int py = find(y);

            if(px == py) return;

            if(rank[px] < rank[py]) parent[px] = py;
            else if(rank[px] > rank[py]) parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
    };

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        int OFFSET = 10001;

        DSU dsu(20005);
        unordered_set<int> uniqueParents;

        // union rows and columns
        for(auto &s : stones) {
            int row = s[0];
            int col = s[1] + OFFSET;
            dsu.unionSet(row, col);
        }

        // count connected components
        for(auto &s : stones) {
            int parent = dsu.find(s[0]);
            uniqueParents.insert(parent);
        }

        return n - uniqueParents.size();
    }
};
