//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int minimizeCost(int k, int arr[]) {
        // code here
        // Length of the array
        int n = arr.length;
        // DP array to store the minimum cost to reach each index
        int[] dp = new int[n];
        // Initialize dp[0] to 0 because there's no cost to start at index 0
        dp[0] = 0;

        // Iterate through each index from 1 to n-1
        for (int i = 1; i < n; i++) {
            // Initialize dp[i] to a large value (infinity)
            dp[i] = Integer.MAX_VALUE;

            // Check up to k steps back
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    // Update dp[i] with the minimum cost
                    dp[i] = Math.min(dp[i], dp[i - j] + Math.abs(arr[i] - arr[i - j]));
                }
            }
        }

        // Return the minimum cost to reach the last index
        return dp[n - 1];
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.minimizeCost(k, arr);

            System.out.println(res);
        }
    }
}
// } Driver Code Ends
