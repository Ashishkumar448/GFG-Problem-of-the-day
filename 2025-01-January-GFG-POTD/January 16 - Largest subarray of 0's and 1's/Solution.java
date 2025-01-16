//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create BufferedReader for efficient input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read number of test cases
        int T = Integer.parseInt(br.readLine());

        // Process each test case
        while (T-- > 0) {
            // Read the entire line containing the array elements
            String line = br.readLine();

            // Split the line into an array of strings, then parse them as integers
            String[] tokens = line.split("\\s+");
            int[] a = new int[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                a[i] = Integer.parseInt(tokens[i]);
            }

            // Create the Solution object
            Solution obj = new Solution();

            // Call maxLen function and print the result
            System.out.println(obj.maxLen(a));
        }
    }
}
// } Driver Code Ends


class Solution {
    public int maxLen(int[] arr) {
        // Your code here
         // Map to store the first occurrence of a prefix sum
        Map<Integer, Integer> map = new HashMap<>();
        
        int maxLength = 0;  // Stores the maximum length of subarray
        int sum = 0;        // Tracks the cumulative sum
        
        for (int i = 0; i < arr.length; i++) {
            // Treat 0 as -1 for the purpose of summing
            sum += (arr[i] == 0) ? -1 : 1;
            
            if (sum == 0) {
                // If sum is 0, subarray from start to current index has equal 0's and 1's
                maxLength = i + 1;
            }
            
            // If this sum has been seen before
            if (map.containsKey(sum)) {
                // Calculate the length of the subarray
                int previousIndex = map.get(sum);
                maxLength = Math.max(maxLength, i - previousIndex);
            } else {
                // Store the first occurrence of this sum
                map.put(sum, i);
            }
        }
        
        return maxLength;
    }
}
