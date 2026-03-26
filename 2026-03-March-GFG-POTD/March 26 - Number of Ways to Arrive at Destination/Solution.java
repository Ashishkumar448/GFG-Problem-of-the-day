class Solution {
    static final int MOD = (int)1e9 + 7;

    public int countPaths(int V, int[][] edges) {
        // Build adjacency list
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) graph.add(new ArrayList<>());

        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
        }

        // Dijkstra arrays
        long[] dist = new long[V];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;

        long[] ways = new long[V];
        ways[0] = 1;

        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));
        pq.add(new long[]{0, 0});   // {node, dist}

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            int node = (int) curr[0];
            long d = curr[1];

            if (d > dist[node]) continue;

            for (int[] next : graph.get(node)) {
                int neigh = next[0];
                long w = next[1];

                if (d + w < dist[neigh]) {
                    dist[neigh] = d + w;
                    ways[neigh] = ways[node];
                    pq.add(new long[]{neigh, dist[neigh]});
                } 
                else if (d + w == dist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return (int)(ways[V - 1] % MOD);
    }
}
