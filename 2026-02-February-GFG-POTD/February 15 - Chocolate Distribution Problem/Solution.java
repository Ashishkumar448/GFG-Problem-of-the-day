// User function Template for Java

class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        int n = arr.size();
        
        // Edge case
        if (m == 0 || n == 0 || m > n) {
            return 0;
        }
        
        // Sort the array
        Collections.sort(arr);
        
        int minDiff = Integer.MAX_VALUE;
        
        // Check every window of size m
        for (int i = 0; i <= n - m; i++) {
            int diff = arr.get(i + m - 1) - arr.get(i);
            minDiff = Math.min(minDiff, diff);
        }
        
        return minDiff;
    }
}
