//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
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

            int key = Integer.parseInt(in.readLine().trim());

            out.println(new Solution().search(arr, key));

            out.println("~");
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int search(int[] arr, int key) {
        // Complete this function
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if the middle element is the key
            if (arr[mid] == key) {
                return mid;
            }

            // Check which part is sorted
            if (arr[low] <= arr[mid]) {
                // Left part is sorted
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1; // Key lies in the left part
                } else {
                    low = mid + 1; // Key lies in the right part
                }
            } else {
                // Right part is sorted
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1; // Key lies in the right part
                } else {
                    high = mid - 1; // Key lies in the left part
                }
            }
        }

        // Key not found
        return -1;
    }
}
