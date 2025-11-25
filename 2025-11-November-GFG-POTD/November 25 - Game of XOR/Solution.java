class Solution {
    public int subarrayXor(int[] arr) {
        int n = arr.length;
        int ans = 0;

        // Only when n is odd do we get contributions
        if (n % 2 == 1) {
            for (int i = 0; i < n; i += 2) { 
                ans ^= arr[i];  // XOR only even index elements
            }
        }

        return ans;
    }
}
