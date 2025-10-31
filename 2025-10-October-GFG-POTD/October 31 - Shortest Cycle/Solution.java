class Solution {
    public int shortCycle(int V, int[][] edges) {
        // Build adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        int ans = Integer.MAX_VALUE;

        // Try BFS from each node
        for (int start = 0; start < V; start++) {
            int[] dist = new int[V];
            Arrays.fill(dist, -1);
            Queue<Integer> q = new LinkedList<>();

            dist[start] = 0;
            q.add(start);

            while (!q.isEmpty()) {
                int u = q.poll();

                for (int v : adj.get(u)) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.add(v);
                    } else if (dist[v] >= dist[u]) {
                        // A cycle is found
                        ans = Math.min(ans, dist[v] + dist[u] + 1);
                    }
                }
            }
        }

        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}
