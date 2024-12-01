//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Driverclass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String st = sc.next();

            char ans = new Solution().nonRepeatingChar(st);

            if (ans != '$')
                System.out.println(ans);
            else
                System.out.println(-1);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find the first non-repeating character in a string.
    static char nonRepeatingChar(String s) {
        // Your code here
         // Step 1: Create a frequency map to count occurrences of each character
        Map<Character, Integer> freqMap = new HashMap<>();
        
        // Step 2: Populate the frequency map
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }
        
        // Step 3: Traverse the string again to find the first non-repeating character
        for (char c : s.toCharArray()) {
            if (freqMap.get(c) == 1) {
                return c; // Return the first non-repeating character
            }
        }
        
        // Step 4: If no non-repeating character is found, return '$'
        return '$';
    }
}
