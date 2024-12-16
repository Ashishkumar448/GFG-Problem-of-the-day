//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine().trim());

            String[] line1 = br.readLine().trim().split(" ");
            int[] a = new int[line1.length];
            for (int i = 0; i < line1.length; i++) {
                a[i] = Integer.parseInt(line1[i]);
            }

            String[] line2 = br.readLine().trim().split(" ");
            int[] b = new int[line2.length];
            for (int i = 0; i < line2.length; i++) {
                b[i] = Integer.parseInt(line2[i]);
            }

            Solution ob = new Solution();
            System.out.println(ob.kthElement(a, b, k));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int kthElement(int a[], int b[], int k) {
        // code here
         // Ensure `a` is the smaller array
        if (a.length > b.length) {
            return kthElement(b, a, k);
        }

        int n = a.length;
        int m = b.length;

        // Define the binary search range
        int low = Math.max(0, k - m);
        int high = Math.min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            // Handle out-of-bound elements
            int leftA = (cut1 == 0) ? Integer.MIN_VALUE : a[cut1 - 1];
            int leftB = (cut2 == 0) ? Integer.MIN_VALUE : b[cut2 - 1];
            int rightA = (cut1 == n) ? Integer.MAX_VALUE : a[cut1];
            int rightB = (cut2 == m) ? Integer.MAX_VALUE : b[cut2];

            // Check if we found the correct partition
            if (leftA <= rightB && leftB <= rightA) {
                return Math.max(leftA, leftB);
            } else if (leftA > rightB) {
                // Move towards the left in `a`
                high = cut1 - 1;
            } else {
                // Move towards the right in `a`
                low = cut1 + 1;
            }
        }

        // If the function reaches here, the input is invalid
        return -1; 
    }
}
