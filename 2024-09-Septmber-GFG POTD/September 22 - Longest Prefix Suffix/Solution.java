//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.lps(s));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int lps(String str) {
        // code here
        int n = str.length();
        int[] lpsArray = new int[n];
        
        int length = 0;  // length of previous longest prefix suffix
        int i = 1;

        // LPS[0] is always 0, no proper prefix or suffix for single character
        lpsArray[0] = 0;
        
        while (i < n) {
            if (str.charAt(i) == str.charAt(length)) {
                length++;
                lpsArray[i] = length;
                i++;
            } else {
                if (length != 0) {
                    // Try finding shorter prefix
                    length = lpsArray[length - 1];
                } else {
                    lpsArray[i] = 0;
                    i++;
                }
            }
        }
        
        // Return the last value in the lpsArray which represents the longest prefix suffix
        return lpsArray[n - 1];
    }
}
