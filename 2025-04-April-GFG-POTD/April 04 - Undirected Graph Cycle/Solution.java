//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
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
            boolean ans = obj.isCycle(V, edges);
            System.out.println(ans ? "true" : "false");
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public boolean isCycle(int V, int[][] edges) {
        int[] parent = new int[V];

        // Initialize each node's parent to itself
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int parentU = find(u, parent);
            int parentV = find(v, parent);

            // If both vertices have the same parent, a cycle is found
            if (parentU == parentV) {
                return true;
            }

            // Union the sets
            parent[parentU] = parentV;
        }

        return false;
    }

    // Find with path compression
    private int find(int node, int[] parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }
}
