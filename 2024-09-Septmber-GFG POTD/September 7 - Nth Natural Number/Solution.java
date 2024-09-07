// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        int t = ob.nextInt();
        while (t-- > 0) {
            long n = ob.nextLong();
            Solution ab = new Solution();
            long k = ab.findNth(n);
            System.out.println(k);
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    long findNth(long n) {
        // Convert n to a number in base 9 to skip the digit 9
        long result = 0;
        long place = 1;
        
        // Continue until n is reduced to zero
        while (n > 0) {
            // Append the remainder when divided by 9 to the result
            result += (n % 9) * place;
            // Move to the next digit
            n /= 9;
            // Update the place value to the next power of 10
            place *= 10;
        }
        return result;
    }
}
