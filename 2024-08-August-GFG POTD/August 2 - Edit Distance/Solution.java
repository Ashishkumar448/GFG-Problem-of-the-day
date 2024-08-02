//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String[] S = s1.split(" ");
            String s = S[0];
            String t = S[1];
            Solution ob = new Solution();
            int ans = ob.editDistance(s, t);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {
    public int editDistance(String s1, String s2) {
        // Code here
        int m = s1.length();
        int n = s2.length();
        int[][] dp = new int[m + 1][n + 1];

        // Fill dp array
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // If the first string is empty, the only option is to insert all characters of the second string
                if (i == 0) {
                    dp[i][j] = j;
                }
                // If the second string is empty, the only option is to remove all characters of the first string
                else if (j == 0) {
                    dp[i][j] = i;
                }
                // If the characters are the same, no operation is needed, take the diagonal value
                else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // If the characters are different, consider all possibilities (insert, delete, substitute) and take the minimum
                else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], // delete
                                            Math.min(dp[i][j - 1], // insert
                                                     dp[i - 1][j - 1])); // substitute
                }
            }
        }
        return dp[m][n];
    }
}
