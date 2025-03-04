//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine()); // Number of test cases
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine())
                               .trim()
                               .split(" "); // Read the input for the current test case
            int arr[] = new int[str.length];
            // Convert input string into an integer array
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }
            // Call the solution method and print the result
            System.out.println(new Solution().lis(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
     static int lis(int arr[]) {
        int n = arr.length;
        int[] dp = new int[n]; // dp[i] will store the length of LIS ending at index i
        
        // Initialize dp array with 1, as a single element is always an increasing subsequence of length 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        
        // Compute the length of LIS ending at each position
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    // Update dp[i] if a longer increasing subsequence is found
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // Find the maximum length in the dp array
        int maxLen = dp[0];
        for (int i = 1; i < n; i++) {
            maxLen = Math.max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
}
