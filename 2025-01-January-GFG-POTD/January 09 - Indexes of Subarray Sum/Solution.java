//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim());

        while (t-- > 0) {
            String line = read.readLine().trim();
            String[] numsStr = line.split(" ");
            int[] nums = new int[numsStr.length];
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int d = Integer.parseInt(read.readLine().trim());

            Solution ob = new Solution();
            ArrayList<Integer> result = ob.subarraySum(nums, d);
            // Print all elements in the result list
            for (int i : result) {
                System.out.print(i + " ");
            }
            System.out.println(); // Print a new line after the result
            System.out.println("~");
        }
    }
}

// } Driver Code Ends



class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int target) {
        // code here
        ArrayList<Integer> result = new ArrayList<>();
        int n = arr.length;
        int currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            // Add current element to the current sum
            currentSum += arr[end];

            // Shrink the window while the current sum is greater than the target
            while (currentSum > target && start <= end) {
                currentSum -= arr[start];
                start++;
            }

            // Check if the current sum equals the target
            if (currentSum == target) {
                result.add(start + 1); // 1-based index
                result.add(end + 1);   // 1-based index
                return result;
            }
        }

        // If no subarray is found, return [-1]
        result.add(-1);
        return result;
    }
}
