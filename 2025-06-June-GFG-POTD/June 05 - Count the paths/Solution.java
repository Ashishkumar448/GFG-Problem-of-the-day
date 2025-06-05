class Solution {
    public int countPaths(int[][] edges, int V, int src, int dest) {
        // Create the adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
        }

        // Memoization array to store number of paths from each node to dest
        int[] memo = new int[V];
        Arrays.fill(memo, -1);

        return dfs(src, dest, graph, memo);
    }

    private int dfs(int node, int dest, List<List<Integer>> graph, int[] memo) {
        if (node == dest) return 1; // Base case: reached destination
        if (memo[node] != -1) return memo[node]; // Return cached result

        int totalPaths = 0;
        for (int neighbor : graph.get(node)) {
            totalPaths += dfs(neighbor, dest, graph, memo);
        }

        memo[node] = totalPaths; // Cache the result
        return totalPaths;
    }
}
