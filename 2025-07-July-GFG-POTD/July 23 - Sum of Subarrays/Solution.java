class Solution {
    public int subarraySum(int[] arr) {
        int n = arr.length;
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            // Each element contributes to (i+1)*(n-i) subarrays
            totalSum += arr[i] * (i + 1) * (n - i);
        }
        
        return totalSum;
    }
}
