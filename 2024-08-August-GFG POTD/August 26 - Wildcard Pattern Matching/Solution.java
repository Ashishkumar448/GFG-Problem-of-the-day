// { Driver Code Starts
import java.util.*;

class WildcardPattern {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String pat = sc.nextLine();
            String text = sc.nextLine();
            Solution g = new Solution();
            System.out.println(g.wildCard(pat, text));
            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public int wildCard(String pattern, String str) {
        int n = str.length();
        int m = pattern.length();

        // Create a DP table with default value false
        boolean[][] dp = new boolean[n + 1][m + 1];

        // Empty pattern can match with empty string
        dp[0][0] = true;

        // Only '*' can match with empty string
        for (int j = 1; j <= m; j++) {
            if (pattern.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern.charAt(j - 1) == '*') {
                    // '*' can match with or without the current character of str
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (pattern.charAt(j - 1) == '?' || pattern.charAt(j - 1) == str.charAt(i - 1)) {
                    // '?' or exact match
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        // Return the result
        return dp[n][m] ? 1 : 0;
    }
}
