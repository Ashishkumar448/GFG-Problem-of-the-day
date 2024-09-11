//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine()); // Number of test cases

        while (t-- > 0) {
            String[] input = br.readLine().split(" ");
            long[] a = new long[input.length];

            for (int i = 0; i < input.length; i++) {
                a[i] = Long.parseLong(input[i]);
            }

            Solution ob = new Solution();
            System.out.println(ob.minCost(a));
        }
    }
}

// } Driver Code Ends


// Back-end complete function Template for Java
class Solution {
    // Function to return the minimum cost of connecting the ropes.
    public long minCost(long[] arr) {
        // Create a priority queue (min-heap) to store the rope lengths
        PriorityQueue<Long> pq = new PriorityQueue<>();
        
        // Add all ropes to the priority queue
        for (long rope : arr) {
            pq.add(rope);
        }
        
        long totalCost = 0;
        
        // Combine ropes until only one rope remains
        while (pq.size() > 1) {
            // Remove the two smallest ropes
            long first = pq.poll();
            long second = pq.poll();
            
            // Calculate the cost of connecting these two ropes
            long cost = first + second;
            totalCost += cost;
            
            // Add the combined rope back to the priority queue
            pq.add(cost);
        }
        
        // Return the total cost
        return totalCost;
    }
}