//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.nCr(n, r));
            System.out.println("~");
        }

        sc.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        int mod = 1000000007; // Optional if large values, here you can skip mod if value fits in 32-bit
        int[] dp = new int[r + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Iterate backwards to ensure we use previous row's values
            for (int j = Math.min(i, r); j > 0; j--) {
                dp[j] = (dp[j] + dp[j - 1]); // If using mod: % mod
            }
        }

        return dp[r];
    }
}
