//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {

    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    public int circularSubarraySum(int arr[]) {

        // Your code here
         int n = arr.length;
        
        // Step 1: Find the maximum sum of a normal subarray using Kadane's Algorithm
        int maxNormal = kadane(arr);
        
        // If all elements are negative, maxNormal will be the answer
        if (maxNormal < 0) return maxNormal;
        
        // Step 2: Calculate the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        // Step 3: Find the minimum sum of a normal subarray
        // To get the minimum sum, invert the sign of all elements and apply Kadane's Algorithm
        for (int i = 0; i < n; i++) {
            arr[i] = -arr[i];
        }
        
        int maxInverted = kadane(arr);
        
        // Step 4: Calculate the circular sum and return the maximum
        int maxCircular = totalSum + maxInverted;  // Since we inverted the signs, maxInverted gives -minSum
        
        return Math.max(maxNormal, maxCircular);
    }

    // Kadane's algorithm to find the maximum subarray sum
    private int kadane(int[] arr) {
        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            maxEndingHere = Math.max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
}
