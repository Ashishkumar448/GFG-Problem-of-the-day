class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int n = arr.length;
        
        // XOR of first window
        int currentXor = 0;
        for (int i = 0; i < k; i++) {
            currentXor ^= arr[i];
        }
        
        int maxXor = currentXor;
        
        // Slide the window
        for (int i = k; i < n; i++) {
            currentXor ^= arr[i - k]; // remove left element
            currentXor ^= arr[i];     // add right element
            maxXor = Math.max(maxXor, currentXor);
        }
        
        return maxXor;
    }
}
