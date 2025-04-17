//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int V = Integer.parseInt(sc.nextLine());
            int E = Integer.parseInt(sc.nextLine());

            List<int[]> edgeList = new ArrayList<>();

            for (int i = 0; i < E; i++) {
                String[] parts = sc.nextLine().split(" ");
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                int w = Integer.parseInt(parts[2]);
                edgeList.add(new int[] {u, v, w});
                edgeList.add(new int[] {v, u, w});
            }

            int[][] edges = new int[edgeList.size()][3];
            for (int i = 0; i < edgeList.size(); i++) {
                edges[i] = edgeList.get(i);
            }

            Solution obj = new Solution();
            int res = obj.findMinCycle(V, edges);

            System.out.println(res);
        }

        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public int findMinCycle(int V, int[][] edges) {
        int INF = (int) 1e9;
        int minCycle = INF;

        // Adjacency matrix
        int[][] graph = new int[V][V];

        // Initialize distances to INF
        for (int i = 0; i < V; i++) {
            Arrays.fill(graph[i], INF);
            graph[i][i] = 0;
        }

        // Build the graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u][v] = Math.min(graph[u][v], w);
        }

        // Check each edge by temporarily removing it
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            // Temporarily remove the edge
            int original = graph[u][v];
            graph[u][v] = INF;

            // Floyd-Warshall to compute shortest paths
            int[][] dist = new int[V][V];
            for (int i = 0; i < V; i++)
                dist[i] = Arrays.copyOf(graph[i], V);

            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (dist[i][k] < INF && dist[k][j] < INF)
                            dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            // Check for a cycle through u-v
            if (dist[u][v] < INF)
                minCycle = Math.min(minCycle, dist[u][v] + w);

            // Restore the edge
            graph[u][v] = original;
        }

        return minCycle == INF ? -1 : minCycle;
    }
};
