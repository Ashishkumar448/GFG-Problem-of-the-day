// { Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        
        while(test > 0){
            String s = scan.next();
            String t = scan.next();
            
            System.out.println(new Solution().smallestWindow(s, t));
            test--;
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    public static String smallestWindow(String s, String p) {
        if (s.length() < p.length()) {
            return "-1";  // If the length of p is greater than s, no solution exists
        }

        // Frequency maps to store the count of characters in p and the current window in s
        int[] pFreq = new int[256];
        int[] sFreq = new int[256];

        // Fill frequency map for the pattern string p
        for (char ch : p.toCharArray()) {
            pFreq[ch]++;
        }

        // Initialize pointers for the sliding window
        int start = 0, minLen = Integer.MAX_VALUE, count = 0;
        int startIndex = -1;  // To store the starting index of the smallest window

        // Traverse through string s
        for (int end = 0; end < s.length(); end++) {
            // Include the current character in the window
            char ch = s.charAt(end);
            sFreq[ch]++;

            // If the current character's frequency in the window is less than or equal to its frequency in p
            if (sFreq[ch] <= pFreq[ch]) {
                count++;
            }

            // When all characters are matched (window is valid)
            if (count == p.length()) {
                // Try to minimize the window by moving the start pointer
                while (sFreq[s.charAt(start)] > pFreq[s.charAt(start)] || pFreq[s.charAt(start)] == 0) {
                    if (sFreq[s.charAt(start)] > pFreq[s.charAt(start)]) {
                        sFreq[s.charAt(start)]--;
                    }
                    start++;
                }

                // Update the minimum window length and the start index of the smallest window
                int windowLen = end - start + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = start;
                }
            }
        }

        // If no valid window was found, return "-1"
        return startIndex == -1 ? "-1" : s.substring(startIndex, startIndex + minLen);
    }
}
