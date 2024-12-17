//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            String[] nk = br.readLine().trim().split(" ");
            int k = Integer.parseInt(nk[0]);
            Solution sln = new Solution();
            int ans = sln.aggressiveCows(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public static int aggressiveCows(int[] stalls, int k) {
        // code here
        // Sort the stall positions to facilitate the binary search
        Arrays.sort(stalls);

        // Define the binary search range
        int low = 1; // Minimum possible distance
        int high = stalls[stalls.length - 1] - stalls[0]; // Maximum possible distance
        int result = 0;

        // Binary search to find the largest minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update result if cows can be placed
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }
        return result;
    }

    // Helper function to check if k cows can be placed with at least 'distance' between them
    private static boolean canPlaceCows(int[] stalls, int k, int distance) {
        int count = 1; // Place the first cow in the first stall
        int lastPlacedCow = stalls[0];

        for (int i = 1; i < stalls.length; i++) {
            if (stalls[i] - lastPlacedCow >= distance) {
                count++;
                lastPlacedCow = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }
}
