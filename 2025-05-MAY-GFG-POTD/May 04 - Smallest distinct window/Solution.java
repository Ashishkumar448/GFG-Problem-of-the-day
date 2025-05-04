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
            String str = br.readLine();

            Solution obj = new Solution();
            System.out.println(obj.findSubString(str));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int findSubString(String str) {
        int n = str.length();
        if (n == 0) return 0;

        // Step 1: Count all unique characters
        Set<Character> uniqueChars = new HashSet<>();
        for (char c : str.toCharArray()) {
            uniqueChars.add(c);
        }
        int totalUnique = uniqueChars.size();

        // Step 2: Use sliding window to find smallest substring
        Map<Character, Integer> freqMap = new HashMap<>();
        int minLen = Integer.MAX_VALUE;
        int start = 0, count = 0;

        for (int end = 0; end < n; end++) {
            char endChar = str.charAt(end);
            freqMap.put(endChar, freqMap.getOrDefault(endChar, 0) + 1);

            if (freqMap.get(endChar) == 1) {
                count++; // a new unique character included
            }

            // When we have a window with all unique characters
            while (count == totalUnique) {
                minLen = Math.min(minLen, end - start + 1);

                char startChar = str.charAt(start);
                freqMap.put(startChar, freqMap.get(startChar) - 1);
                if (freqMap.get(startChar) == 0) {
                    count--; // one unique character is out of window
                }
                start++;
            }
        }

        return minLen;
    }
}
