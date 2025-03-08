//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.longestPalindrome(S));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends



class Solution {
      static String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expand(s, i, i);      // Odd length palindrome
            int len2 = expand(s, i, i + 1);  // Even length palindrome
            int currentLen = Math.max(len1, len2);
            
            if (currentLen > maxLength) {
                maxLength = currentLen;
                // Calculate start based on which expansion gave the longer length
                start = (len1 > len2) ? (i - (len1 - 1) / 2) : (i - (len2 / 2 - 1));
            }
        }
        return s.substring(start, start + maxLength);
    }
    
    private static int expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1; // Length of the palindrome found
    }
}
