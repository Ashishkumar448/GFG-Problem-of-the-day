//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.articulationPoints(V, edges);
            Collections.sort(ans);
            for (int val : ans) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
     static int timer;
    
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        int[] tin = new int[V];
        int[] low = new int[V];
        boolean[] visited = new boolean[V];
        boolean[] isArticulation = new boolean[V];
        timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, tin, low, visited, isArticulation);
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) res.add(i);
        }

        if (res.size() == 0) res.add(-1);
        return res;
    }

    static void dfs(int u, int parent, ArrayList<ArrayList<Integer>> adj,
                    int[] tin, int[] low, boolean[] visited, boolean[] isArticulation) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj.get(u)) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u, adj, tin, low, visited, isArticulation);
                low[u] = Math.min(low[u], low[v]);

                if (low[v] >= tin[u] && parent != -1) {
                    isArticulation[u] = true;
                }

                children++;
            } else {
                low[u] = Math.min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }
}
