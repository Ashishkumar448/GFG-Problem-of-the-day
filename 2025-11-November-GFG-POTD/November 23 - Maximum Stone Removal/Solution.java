class Solution {
    class DSU {
        int parent[];
        int rank[];

        DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void union(int x, int y) {
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
    }

    int maxRemove(int[][] stones) {
        int n = stones.length;
        int OFFSET = 10001;

        DSU dsu = new DSU(20005);
        HashSet<Integer> uniqueParents = new HashSet<>();

        // Union rows and columns
        for(int[] s : stones) {
            int row = s[0];
            int col = s[1] + OFFSET;
            dsu.union(row, col);
        }

        // Count unique connected components
        for(int[] s : stones) {
            int parent = dsu.find(s[0]);
            uniqueParents.add(parent);
        }

        // Max stones removable
        return n - uniqueParents.size();
    }
};
