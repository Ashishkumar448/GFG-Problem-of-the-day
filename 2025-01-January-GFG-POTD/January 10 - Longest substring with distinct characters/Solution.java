//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.HashMap;
import java.util.HashSet;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.longestUniqueSubstr(s));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int longestUniqueSubstr(String s) {
        // code here
        if (s == null || s.isEmpty()) return 0;

        // Map to store the last seen index of each character
        HashMap<Character, Integer> lastSeen = new HashMap<>();
        
        int maxLength = 0; // To store the maximum length of the substring
        int start = 0; // Start index of the current window

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);

            // If the character is already in the map, update the start index
            if (lastSeen.containsKey(currentChar)) {
                start = Math.max(start, lastSeen.get(currentChar) + 1);
            }

            // Update the last seen index of the current character
            lastSeen.put(currentChar, end);

            // Calculate the current window length and update maxLength
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }
}
