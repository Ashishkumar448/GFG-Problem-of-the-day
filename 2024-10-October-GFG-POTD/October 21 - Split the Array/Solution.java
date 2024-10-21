import java.util.*;
import java.io.*;

class Solution {
    public int countgroup(ArrayList<Integer> arr) {
        int mod = 1000000007;
        int xr = 0;
        int n = arr.size();
        
        // XOR all elements
        for (int i = 0; i < n; i++) {
            xr ^= arr.get(i);
        }
        
        // If the XOR is non-zero, return 0
        if (xr != 0) return 0;

        // Calculate the result
        long ans = 1;
        for (int i = 0; i < n - 1; i++) {
            ans = (ans * 2) % mod;
        }

        return (int)(ans - 1);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        while (t-- > 0) {
            ArrayList<Integer> arr = new ArrayList<>();
            String[] input = br.readLine().split(" ");
            
            for (String s : input) {
                arr.add(Integer.parseInt(s));
            }
            
            Solution obj = new Solution();
            int ans = obj.countgroup(arr);
            System.out.println(ans);
        }
    }
}
