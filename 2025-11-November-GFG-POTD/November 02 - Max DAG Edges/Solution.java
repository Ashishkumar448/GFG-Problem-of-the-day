class Solution {
     public int maxEdgesToAdd(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) adj.get(e[0]).add(e[1]);

        int[] indegree = new int[V];
        for (int[] e : edges) indegree[e[1]]++;

        // Topological Sort
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) if (indegree[i] == 0) q.add(i);

        List<Integer> topo = new ArrayList<>();
        while (!q.isEmpty()) {
            int u = q.poll();
            topo.add(u);
            for (int v : adj.get(u)) {
                indegree[v]--;
                if (indegree[v] == 0) q.add(v);
            }
        }

        int[] pos = new int[V];
        for (int i = 0; i < V; i++) pos[topo.get(i)] = i;

        // Reachability matrix
        boolean[][] reachable = new boolean[V][V];
        for (int i = 0; i < V; i++) dfs(i, adj, reachable, i);

        // Count additional possible edges
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && pos[i] < pos[j] && !reachable[j][i] && !adj.get(i).contains(j)) {
                    count++;
                }
            }
        }

        return count;
    }

    private void dfs(int src, List<List<Integer>> adj, boolean[][] reachable, int node) {
        for (int nei : adj.get(node)) {
            if (!reachable[src][nei]) {
                reachable[src][nei] = true;
                dfs(src, adj, reachable, nei);
            }
        }
    }
}
