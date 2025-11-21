class Solution {
     static class Pair {
        int v, w;
        Pair(int v, int w) { this.v = v; this.w = w; }
    }

    static final int INF = Integer.MAX_VALUE;

    private int[] dijkstra(int src, int V, ArrayList<ArrayList<Pair>> adj) {
        int[] dist = new int[V];
        Arrays.fill(dist, INF);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.w - b.w);
        pq.add(new Pair(src, 0));
        dist[src] = 0;

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            int u = cur.v, d = cur.w;

            if (d != dist[u]) continue;  // stale entry

            for (Pair p : adj.get(u)) {
                int v = p.v, w = p.w;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }
        return dist;
    }

    public int shortestPath(int V, int a, int b, int[][] edges) {

        // Graph with ONLY straight edges
        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        // Build adjacency for straight edges
        for (int[] e : edges) {
            int x = e[0], y = e[1], w1 = e[2];
            adj.get(x).add(new Pair(y, w1));
            adj.get(y).add(new Pair(x, w1));
        }

        // Dijkstra from a and b
        int[] distA = dijkstra(a, V, adj);
        int[] distB = dijkstra(b, V, adj);

        long ans = distA[b];  // case: no curved edge

        // Try using each curved edge ONCE
        for (int[] e : edges) {
            int x = e[0], y = e[1], w2 = e[3];

            if (distA[x] != INF && distB[y] != INF)
                ans = Math.min(ans, (long) distA[x] + w2 + distB[y]);

            if (distA[y] != INF && distB[x] != INF)
                ans = Math.min(ans, (long) distA[y] + w2 + distB[x]);
        }

        return ans >= INF ? -1 : (int) ans;
    }
}
