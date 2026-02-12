class Solution {
    
    public int minCost(int[] heights, int[] cost) {
        int n = heights.length;
        
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;
        
        for (int h : heights) {
            low = Math.min(low, h);
            high = Math.max(high, h);
        }
        
        long answer = Long.MAX_VALUE;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long cost1 = calculateCost(heights, cost, mid);
            long cost2 = calculateCost(heights, cost, mid + 1);
            
            answer = Math.min(cost1, cost2);
            
            if (cost1 < cost2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return (int) answer;
    }
    
    private long calculateCost(int[] heights, int[] cost, int target) {
        long total = 0;
        
        for (int i = 0; i < heights.length; i++) {
            total += (long) Math.abs(heights[i] - target) * cost[i];
        }
        
        return total;
    }
}
