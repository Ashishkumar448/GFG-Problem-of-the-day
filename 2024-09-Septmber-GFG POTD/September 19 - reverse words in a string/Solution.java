//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.reverseWords(s));
            t--;
        }
    }
}

// } Driver Code Ends



class Solution {
    // Function to reverse words in a given string.
    String reverseWords(String str) {
        // code here
        // Split the string by the dot (.) character
        String[] words = str.split("\\.");
        // Use StringBuilder to build the reversed string
        StringBuilder reversed = new StringBuilder();
        
        // Reverse the order of words
        for (int i = words.length - 1; i >= 0; i--) {
            reversed.append(words[i]);
            // Add a dot after each word except the last one
            if (i > 0) {
                reversed.append(".");
            }
        }
        
        return reversed.toString();

    }
}
