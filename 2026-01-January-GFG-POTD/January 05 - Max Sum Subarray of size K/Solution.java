class Solution {
     public int maxSubarraySum(int[] arr, int k) {
        int n = arr.length;
        
        // Sum of first window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        int maxSum = windowSum;
        
        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }
        
        return maxSum;
    }
}
