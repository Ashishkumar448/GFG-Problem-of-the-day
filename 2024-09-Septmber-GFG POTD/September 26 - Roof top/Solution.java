// { Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class gfg {

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String st[] = read.readLine().trim().split("\\s+");
            int n = st.length;
            int arr[] = new int[n];

            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st[i]);

            System.out.println(new Solution().maxStep(arr));
        }
    }
}

// } Driver Code Ends

class Solution {
    // Function to find the maximum number of consecutive steps
    // where we see an increase in altitude with each step.
    public int maxStep(int arr[]) {
        int maxSteps = 0;  // Variable to keep track of the maximum steps
        int currentSteps = 0;  // Variable to count current consecutive steps

        // Traverse through the array of building heights
        for (int i = 1; i < arr.length; i++) {
            // If current building is taller than the previous one, increment the step count
            if (arr[i] > arr[i - 1]) {
                currentSteps++;
                // Update maxSteps if currentSteps is greater
                maxSteps = Math.max(maxSteps, currentSteps);
            } else {
                // Reset currentSteps to 0 if the next building is not taller
                currentSteps = 0;
            }
        }

        return maxSteps;
    }
}
