// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}

// User function Template for Java

class Solution {

    public boolean isValid(String str) {
        // Split the string by "."
        String[] parts = str.split("\\.");
        
        // Check if the IP address has exactly 4 parts
        if (parts.length != 4) {
            return false;
        }
        
        for (String part : parts) {
            // Check if the part is a valid integer and within the range [0, 255]
            try {
                int num = Integer.parseInt(part);
                if (num < 0 || num > 255) {
                    return false;
                }
            } catch (NumberFormatException e) {
                return false; // The part is not a valid integer
            }
        }
        
        return true;
    }
}
