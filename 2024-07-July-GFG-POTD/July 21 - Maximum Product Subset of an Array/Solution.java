//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            int n = sc.nextInt();
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < n; i++) list.add(sc.nextInt());

            Solution obj = new Solution();
            long ans = obj.findMaxProduct(list);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


class Solution {
    public long findMaxProduct(List<Integer> arr) {
        // code here
       int n = arr.size();
        int neg = 0, zero = 0;
        int negative = Integer.MIN_VALUE;
        long prod = 1;
        int mod = 1000000007;
        
        for (int i = 0; i < n; i++) {
            int value = arr.get(i);
            if (value == 0) {
                zero++;
            } else if (value < 0) {
                neg++;
                negative = Math.max(negative, value);
                prod *= value;
            } else {
                prod *= value;
            }
            prod %= mod;
        }
        
        if (zero == n) return 0;
        if (neg == 1 && zero == n - 1) return 0;
        if (neg % 2 == 0) return prod;
        if (neg % 2 == 1) prod = prod / negative;
        
        return prod;
    }
}
