class Solution {
    // DSU for Kruskal
    class DSU {
        int[] p, r;
        DSU(int n){
            p = new int[n];
            r = new int[n];
            for(int i = 0; i < n; i++) p[i] = i;
        }
        int find(int x){
            return p[x] == x ? x : (p[x] = find(p[x]));
        }
        boolean union(int a, int b){
            a = find(a); b = find(b);
            if(a == b) return false;
            if(r[a] < r[b]) p[a] = b;
            else if(r[b] < r[a]) p[b] = a;
            else { p[b] = a; r[a]++; }
            return true;
        }
    }

    // Build MST, optionally skipping exactly one edge
    int buildMST(int V, int[][] edges, int skipU, int skipV, int skipW){
        DSU d = new DSU(V);
        int sum = 0, used = 0;

        for(int[] e : edges){
            if(e[0] == skipU && e[1] == skipV && e[2] == skipW) continue;
            if(d.union(e[0], e[1])){
                sum += e[2];
                used++;
            }
        }
        return (used == V - 1) ? sum : Integer.MAX_VALUE;
    }

    public int secondMST(int V, int[][] edges) {

        // Sort edges by weight
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);

        // Build the true MST
        int mstWeight = buildMST(V, edges, -1, -1, -1);
        if(mstWeight == Integer.MAX_VALUE) return -1; // no MST

        int secondBest = Integer.MAX_VALUE;

        // Try removing each MST edge one by one
        for(int[] e : edges){
            int w = buildMST(V, edges, e[0], e[1], e[2]);
            if(w > mstWeight) secondBest = Math.min(secondBest, w);
        }

        return (secondBest == Integer.MAX_VALUE ? -1 : secondBest);
    }
}
