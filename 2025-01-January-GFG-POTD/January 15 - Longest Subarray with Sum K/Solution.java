//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim()); // Read number of test cases

        while (t-- > 0) {
            String line = read.readLine().trim(); // Read the array input
            String[] numsStr = line.split(" ");   // Split the input string by spaces
            int[] nums =
                new int[numsStr.length]; // Convert string array to integer array
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int k = Integer.parseInt(read.readLine().trim()); // Read target sum

            Solution ob = new Solution();
            int ans = ob.longestSubarray(nums, k); // Call the function and store result
            System.out.println(ans);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int longestSubarray(int[] arr, int k) {
        // code here
        Map<Integer, Integer> prefixSumMap = new HashMap<>();
        int prefixSum = 0;
        int maxLength = 0;

        // Iterate through the array
        for (int i = 0; i < arr.length; i++) {
            prefixSum += arr[i]; // Update prefix sum

            // Check if prefixSum equals k
            if (prefixSum == k) {
                maxLength = i + 1; // Update maxLength for the entire array up to this point
            }

            // Check if (prefixSum - k) exists in the map
            if (prefixSumMap.containsKey(prefixSum - k)) {
                // Calculate the length of the subarray and update maxLength
                maxLength = Math.max(maxLength, i - prefixSumMap.get(prefixSum - k));
            }

            // Store prefixSum in the map if not already present
            prefixSumMap.putIfAbsent(prefixSum, i);
        }

        return maxLength;
    }
}
