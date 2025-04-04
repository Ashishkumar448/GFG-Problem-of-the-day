// { Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            long ans = ob.nthStair(n);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Solution {
    public long nthStair(int n) {
        // As order does not matter, we only need to count distinct combinations
        // For a given n, the result is (n / 2) + 1
        return (n / 2) + 1;
    }
}
