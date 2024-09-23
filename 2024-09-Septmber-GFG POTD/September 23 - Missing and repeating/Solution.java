//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solve {
    int[] findTwoElement(int arr[]) {
        // code here
        int n = arr.length;
        
        // Expected sum and sum of squares of first n natural numbers
        long S_n = (long)n * (n + 1) / 2;
        long S_sq_n = (long)n * (n + 1) * (2 * n + 1) / 6;
        
        // Actual sum and sum of squares of the array
        long S_arr = 0, S_sq_arr = 0;
        for (int i = 0; i < n; i++) {
            S_arr += arr[i];
            S_sq_arr += (long)arr[i] * arr[i];
        }
        
        // Calculating the differences
        long diff1 = S_n - S_arr;          // X - Y
        long diff2 = S_sq_n - S_sq_arr;    // X^2 - Y^2 = (X - Y) * (X + Y)
        
        long sumXY = diff2 / diff1;        // X + Y
        
        // Solving for X and Y
        int X = (int)( (diff1 + sumXY) / 2 );
        int Y = (int)( sumXY - X );
        
        return new int[]{Y, X}; 
    }
}
