//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String a, b;
            a = sc.next();
            b = sc.next();
            Solution ob = new Solution();
            System.out.println(ob.addBinary(a, b));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public String addBinary(String s1, String s2) {
        // code here
         StringBuilder result = new StringBuilder();
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;

        // Traverse both strings starting from their rightmost digits
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry; // Initialize sum with carry

            if (i >= 0) {
                sum += s1.charAt(i) - '0'; // Add s1's digit
                i--;
            }
            if (j >= 0) {
                sum += s2.charAt(j) - '0'; // Add s2's digit
                j--;
            }

            result.append(sum % 2);  // Append current bit (0 or 1)
            carry = sum / 2;         // Update carry
        }

        // Reverse the result as the current string is in reverse order
        result.reverse();

        // Remove leading zeros
        while (result.length() > 1 && result.charAt(0) == '0') {
            result.deleteCharAt(0);
        }

        return result.toString();
    }
}
