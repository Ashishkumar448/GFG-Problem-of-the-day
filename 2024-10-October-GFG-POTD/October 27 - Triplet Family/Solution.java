//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;

// } Driver Code Ends

class Solution {
    public boolean findTriplet(int[] arr) {
        int n = arr.length;
        
        // Sort the array to use the two-pointer technique
        Arrays.sort(arr);
        
        // Iterate through each element to see if it can be the sum of any two others
        for (int i = 0; i < n; i++) {
            int target = arr[i];  // Assume arr[i] is the sum of two other elements
            int left = 0;         // Start pointer
            int right = n - 1;    // End pointer
            
            // Adjust left and right pointers to avoid using the target element itself
            while (left < right) {
                if (left == i) left++;  // Skip if left pointer is on the target element
                if (right == i) right--; // Skip if right pointer is on the target element
                
                // Sum of two elements
                int sum = arr[left] + arr[right];
                
                if (sum == target) {
                    return true; // Found a triplet where sum of two elements equals the third
                } else if (sum < target) {
                    left++; // Move left pointer right to increase the sum
                } else {
                    right--; // Move right pointer left to decrease the sum
                }
            }
        }
        
        return false; // No such triplet found
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine()); // Number of test cases
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");
            
            ArrayList<Integer> array = new ArrayList<>();
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }
            
            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            boolean res = obj.findTriplet(arr);
            if (res)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends
