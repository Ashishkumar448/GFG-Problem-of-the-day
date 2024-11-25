//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String[] inputLine = br.readLine().split(" ");
            int n = inputLine.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            System.out.println(new Solution().maxProduct(arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    int maxProduct(int[] arr) {
        // code here
        int n = arr.length;
        
        // Initialize the maximum and minimum product ending at the current position
        int currentMax = arr[0];
        int currentMin = arr[0];
        
        // Initialize the result with the first element
        int maxProduct = arr[0];
        
        // Traverse through the array from the second element
        for (int i = 1; i < n; i++) {
            int temp = currentMax;
            
            // Update currentMax and currentMin based on the current element
            currentMax = Math.max(arr[i], Math.max(currentMax * arr[i], currentMin * arr[i]));
            currentMin = Math.min(arr[i], Math.min(temp * arr[i], currentMin * arr[i]));
            
            // Update the result with the maximum product so far
            maxProduct = Math.max(maxProduct, currentMax);
        }
        
        return maxProduct;
    }
}
