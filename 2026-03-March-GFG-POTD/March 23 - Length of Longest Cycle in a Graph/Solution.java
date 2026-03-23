class Solution {
    public int longestCycle(int V, int[][] edges) {
        int[] adj = new int[V];
        for (int i = 0; i < V; i++) adj[i] = -1;

        for (int[] e : edges) {
            adj[e[0]] = e[1];
        }

        boolean[] visited = new boolean[V];
        int[] timeVisited = new int[V];
        int[] visId = new int[V]; // tracks traversal id

        int maxCycle = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;

            int curr = i;
            int time = 0;

            // traverse this path
            while (curr != -1 && !visited[curr]) {
                visited[curr] = true;
                timeVisited[curr] = time;
                visId[curr] = i; // mark traversal origin
                time++;
                curr = adj[curr];
            }

            // check if it's a cycle in SAME traversal
            if (curr != -1 && visId[curr] == i) {
                int cycleLength = time - timeVisited[curr];
                maxCycle = Math.max(maxCycle, cycleLength);
            }
        }

        return maxCycle;
    }
}
