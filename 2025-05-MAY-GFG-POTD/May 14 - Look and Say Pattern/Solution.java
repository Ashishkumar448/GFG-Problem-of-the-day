//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            System.out.println(ob.countAndSay(n));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public String countAndSay(int n) {
        if (n <= 0) return "";
        
        String result = "1";
        
        for (int i = 2; i <= n; i++) {
            StringBuilder current = new StringBuilder();
            int count = 1;
            char prev = result.charAt(0);
            
            for (int j = 1; j < result.length(); j++) {
                char ch = result.charAt(j);
                if (ch == prev) {
                    count++;
                } else {
                    current.append(count).append(prev);
                    prev = ch;
                    count = 1;
                }
            }
            
            current.append(count).append(prev);  // Append the last group
            result = current.toString();
        }
        
        return result;
    }
}
