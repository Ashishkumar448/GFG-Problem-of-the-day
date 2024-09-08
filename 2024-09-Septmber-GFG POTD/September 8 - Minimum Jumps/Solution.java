//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
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

            System.out.println(new Solution().minJumps(arr));
            // System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static int minJumps(int[] arr) {
        // your code here
        // Edge case: If the array length is 1, no jumps are needed.
        if (arr.length == 1) {
            return 0;
        }

        // If the first element is 0, you can't move anywhere.
        if (arr[0] == 0) {
            return -1;
        }

        // Initialize variables
        int maxReach = arr[0]; // The farthest point that can be reached.
        int steps = arr[0];    // Steps that can be taken with the current jump.
        int jumps = 1;         // Number of jumps made.

        // Start traversing the array
        for (int i = 1; i < arr.length; i++) {
            // Check if we have reached the last element.
            if (i == arr.length - 1) {
                return jumps;
            }

            // Update the farthest point that can be reached.
            maxReach = Math.max(maxReach, i + arr[i]);

            // Use a step to move forward.
            steps--;

            // If no steps are remaining
            if (steps == 0) {
                // We must have used a jump.
                jumps++;

                // If the current index is beyond the maximum reach, return -1.
                if (i >= maxReach) {
                    return -1;
                }

                // Reinitialize steps with the amount of steps to reach maxReach from position i.
                steps = maxReach - i;
            }
        }

        // If we haven't returned inside the loop, it's impossible to reach the end.
        return -1;
    }
}
