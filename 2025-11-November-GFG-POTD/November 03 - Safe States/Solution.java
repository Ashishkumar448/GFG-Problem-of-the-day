class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> reverseGraph = new ArrayList<>();
        for (int i = 0; i < V; i++) reverseGraph.add(new ArrayList<>());

        int[] outdegree = new int[V];

        // Build reverse graph and count outdegree
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            reverseGraph.get(v).add(u);
            outdegree[u]++;
        }

        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> safe = new ArrayList<>();

        // Start with terminal nodes (outdegree = 0)
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0)
                q.add(i);
        }

        // Kahn’s Algorithm (topological sort style)
        while (!q.isEmpty()) {
            int node = q.poll();
            safe.add(node);

            for (int prev : reverseGraph.get(node)) {
                outdegree[prev]--;
                if (outdegree[prev] == 0)
                    q.add(prev);
            }
        }

        Collections.sort(safe);
        return safe;
    }
}
