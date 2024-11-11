// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }
            Solution obj = new Solution();
            int A = obj.minIncrements(a);
            System.out.println(A);
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    public int minIncrements(int[] arr) {
        // Sort the array first
        Arrays.sort(arr);
        
        // Initialize increment count
        int increments = 0;
        
        // Iterate through the sorted array
        for (int i = 1; i < arr.length; i++) {
            // If the current element is not greater than the previous element,
            // increment it to make it unique
            if (arr[i] <= arr[i - 1]) {
                int requiredIncrement = arr[i - 1] + 1 - arr[i];
                arr[i] = arr[i - 1] + 1; // Update the current element
                increments += requiredIncrement;
            }
        }
        
        return increments;
    }
}
