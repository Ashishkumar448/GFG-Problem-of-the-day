//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s, patt;
            s = sc.next();
            patt = sc.next();

            Solution ob = new Solution();

            ArrayList<Integer> res = ob.search(patt, s);
            if (res.size() == 0)
                System.out.print("[]");
            else {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    ArrayList<Integer> search(String pat, String txt) {
        // your code here
         ArrayList<Integer> result = new ArrayList<>();
        int M = pat.length();  // Length of pattern
        int N = txt.length();  // Length of text

        // Step 1: Create the LPS array for the pattern
        int[] lps = new int[M];
        computeLPSArray(pat, M, lps);

        // Step 2: Use LPS array to search the pattern in the text
        int i = 0; // Index for txt[]
        int j = 0; // Index for pat[]
        
        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }
            if (j == M) {  // Found a match
                result.add(i - j);
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    // Helper function to create the LPS array
    void computeLPSArray(String pat, int M, int[] lps) {
        int length = 0;  // Length of the previous longest prefix suffix
        int i = 1;
        lps[0] = 0;  // lps[0] is always 0
        
        // Calculate lps[i] for i = 1 to M-1
        while (i < M) {
            if (pat.charAt(i) == pat.charAt(length)) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
}

