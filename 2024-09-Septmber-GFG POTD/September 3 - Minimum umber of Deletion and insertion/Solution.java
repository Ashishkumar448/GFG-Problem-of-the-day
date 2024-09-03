//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s1 = sc.next();
            String s2 = sc.next();
            Solution ob = new Solution();
            System.out.println(ob.minOperations(s1, s2));
        }
    }
}    
// } Driver Code Ends

// User function Template for Java
class Solution {
    public int minOperations(String str1, String str2) { 
        int m = str1.length();
        int n = str2.length();
        int lcsLength = longestCommonSubsequence(str1, str2, m, n);
        
        // Calculate the number of deletions and insertions
        int deletions = m - lcsLength;
        int insertions = n - lcsLength;
        
        // Total operations needed
        return deletions + insertions;
    }
    
    private int longestCommonSubsequence(String s1, String s2, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        
        // Build the dp array from bottom up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n]; // Length of LCS
    }
}
