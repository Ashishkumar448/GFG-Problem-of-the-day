//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver
{
    public static void main(String args[])throws IOException
    {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //reading total testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //reading length of line segment
            int n = Integer.parseInt(read.readLine().trim());
            
            //reading 3 segment lengths
            String str[] = read.readLine().trim().split(" ");
            
            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            int z = Integer.parseInt(str[2]);
            
            //calling method maximizeCuts() of class Solution()
            //and printing the result
            System.out.println(new Solution().maximizeCuts(n, x, y, z));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to find the maximum number of cuts.
    public int maximizeCuts(int n, int x, int y, int z)
    {
        // Creating a dp array with size n+1 and initializing with -1
        int dp[] = new int[n+1];
        Arrays.fill(dp, -1);
        
        // Base case: 0 length segment can have 0 cuts
        dp[0] = 0;
        
        // Filling the dp array
        for (int i = 1; i <= n; i++)
        {
            if (i >= x && dp[i-x] != -1) 
                dp[i] = Math.max(dp[i], dp[i-x] + 1);
            if (i >= y && dp[i-y] != -1) 
                dp[i] = Math.max(dp[i], dp[i-y] + 1);
            if (i >= z && dp[i-z] != -1) 
                dp[i] = Math.max(dp[i], dp[i-z] + 1);
        }
        
        // If dp[n] is still -1, no cuts could be made, so return 0
        return dp[n] == -1 ? 0 : dp[n];
    }
}
