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
            int ans = sln.kthMissing(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int kthMissing(int[] arr, int k) {
        // code here
         int missingCount = 0; // Counts missing numbers
        int current = 1;     // Start from the smallest positive number
        int index = 0;       // Tracks position in the array

        while (true) {
            if (index < arr.length && arr[index] == current) {
                // Current number is in the array, move to the next number
                index++;
            } else {
                // Current number is missing
                missingCount++;
                if (missingCount == k) {
                    return current; // Found the kth missing number
                }
            }
            current++;
        }
    }
}
