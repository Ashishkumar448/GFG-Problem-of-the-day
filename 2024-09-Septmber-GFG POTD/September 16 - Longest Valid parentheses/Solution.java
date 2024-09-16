//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String S = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.maxLength(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int maxLength(String S){
        // code here
        // Stack to store the indices of the characters
        Stack<Integer> stack = new Stack<>();
        // Initialize the stack with -1 to handle edge cases
        stack.push(-1);
        int maxLen = 0;
        
        // Traverse through the string
        for(int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            
            // If it's an opening parenthesis, push its index onto the stack
            if(c == '(') {
                stack.push(i);
            }
            // If it's a closing parenthesis
            else {
                // Pop the top index
                stack.pop();
                
                // If the stack is not empty, calculate the length of the valid substring
                if(!stack.isEmpty()) {
                    maxLen = Math.max(maxLen, i - stack.peek());
                } 
                // If the stack is empty, push the current index as a new base
                else {
                    stack.push(i);
                }
            }
        }
        return maxLen;
    }
}
