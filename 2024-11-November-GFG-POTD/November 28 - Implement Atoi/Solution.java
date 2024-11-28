//{ Driver Code Starts
// Initial template for JAVA

import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String str = sc.nextLine();

            Solution obj = new Solution();
            int num = obj.myAtoi(str);
            System.out.println(num);
            System.out.println("~");
            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public int myAtoi(String s) {
        // Your code here
        int i = 0, n = s.length();
        // Base case: if string is empty
        if (n == 0) return 0;
        
        // Step 1: Skip leading whitespaces
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        // Step 2: Check if the string is entirely whitespaces
        if (i == n) return 0;
        
        // Step 3: Check for sign
        int sign = 1;  // Default positive
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }
        
        // Step 4: Read digits and build the number
        int result = 0;
        while (i < n) {
            char c = s.charAt(i);
            
            // If the character is not a digit, break the loop
            if (c < '0' || c > '9') break;
            
            int digit = c - '0';  // Convert char to int
            
            // Step 5: Check for overflow before updating result
            if (result > (Integer.MAX_VALUE - digit) / 10) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
}
