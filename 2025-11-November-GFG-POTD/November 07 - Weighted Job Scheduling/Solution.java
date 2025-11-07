class Solution {
    public int maxProfit(int[][] jobs) {
        // Sort jobs by end time
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[1], b[1]));
        
        int n = jobs.length;
        int[] dp = new int[n]; // dp[i] stores max profit till job i
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];
            
            // Find last non-conflicting job using binary search
            int l = findLastNonConflict(jobs, i);
            if (l != -1) {
                includeProfit += dp[l];
            }
            
            // Exclude current job
            dp[i] = Math.max(dp[i - 1], includeProfit);
        }
        
        return dp[n - 1];
    }
    
    // Binary search: find last job whose end time <= current job's start time
    private int findLastNonConflict(int[][] jobs, int i) {
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][1] <= jobs[i][0]) {
                if (jobs[mid + 1][1] <= jobs[i][0])
                    low = mid + 1;
                else
                    return mid;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}
