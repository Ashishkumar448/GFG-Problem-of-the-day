class Solution {
    public static ArrayList<Integer> subsetXOR(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        
        // XOR of 1 to n
        int t = 0;
        for (int i = 1; i <= n; i++)
            t ^= i;
        
        // Case 1: XOR already equals n → include all
        if (t == n) {
            for (int i = 1; i <= n; i++)
                ans.add(i);
            return ans;
        }
        
        int x = t ^ n; // value we want to remove if possible
        
        // Case 2: removing single number x works
        if (x >= 1 && x <= n) {
            for (int i = 1; i <= n; i++) {
                if (i != x) ans.add(i);
            }
            return ans;
        }
        
        // Case 3: need to remove two numbers a and b with a ^ b = x
        // Remove the lexicographically optimal pair (largest possible)
        int a = -1, b = -1;
        for (int i = n; i >= 1; i--) {
            int j = i ^ x;
            if (j >= 1 && j <= n && j != i) {
                a = i;
                b = j;
                break;
            }
        }
        
        // Add all except a and b
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b) ans.add(i);
        }
        
        return ans;
    }
}
