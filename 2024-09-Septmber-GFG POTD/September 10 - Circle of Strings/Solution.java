//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String A[] = in.readLine().trim().split(" ");
            int N = Integer.parseInt(A[0]);
            A = in.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.isCircle(A));
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    public int isCircle(String arr[]) {
        // Create an adjacency list
        Map<Character, List<Character>> adj = new HashMap<>();
        // In-degree and out-degree counts
        int[] in = new int[26];
        int[] out = new int[26];
        
        // Initialize adjacency list
        for (char c = 'a'; c <= 'z'; c++) {
            adj.put(c, new ArrayList<>());
        }

        // Populate adjacency list and degree counts
        for (String s : arr) {
            char start = s.charAt(0);
            char end = s.charAt(s.length() - 1);
            adj.get(start).add(end);
            out[start - 'a']++;
            in[end - 'a']++;
        }

        // Check if in-degree and out-degree of each node match
        for (int i = 0; i < 26; i++) {
            if (in[i] != out[i]) {
                return 0;
            }
        }

        // Check if the graph is strongly connected
        if (!isStronglyConnected(arr, adj)) {
            return 0;
        }
        
        return 1;
    }

    private boolean isStronglyConnected(String[] arr, Map<Character, List<Character>> adj) {
        // Find the first character to start the DFS from
        char start = arr[0].charAt(0);

        // Visited arrays for both directions
        boolean[] visited = new boolean[26];
        // Forward DFS
        dfs(start, adj, visited);
        
        // Check if all relevant nodes were visited
        for (String s : arr) {
            if (!visited[s.charAt(0) - 'a']) {
                return false;
            }
        }

        // Transpose graph
        Map<Character, List<Character>> transpose = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) {
            transpose.put(c, new ArrayList<>());
        }

        for (Map.Entry<Character, List<Character>> entry : adj.entrySet()) {
            char u = entry.getKey();
            for (char v : entry.getValue()) {
                transpose.get(v).add(u);
            }
        }

        // Reset visited array
        Arrays.fill(visited, false);
        // Reverse DFS
        dfs(start, transpose, visited);

        // Check if all relevant nodes were visited
        for (String s : arr) {
            if (!visited[s.charAt(0) - 'a']) {
                return false;
            }
        }

        return true;
    }

    private void dfs(char node, Map<Character, List<Character>> adj, boolean[] visited) {
        visited[node - 'a'] = true;
        for (char neighbor : adj.get(node)) {
            if (!visited[neighbor - 'a']) {
                dfs(neighbor, adj, visited);
            }
        }
    }
}
