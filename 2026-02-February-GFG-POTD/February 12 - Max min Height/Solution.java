class Solution {
    public int maxMinHeight(int[] arr, int k, int w) {
        int n = arr.length;
        
        int low = Integer.MAX_VALUE;
        for (int h : arr) {
            low = Math.min(low, h);
        }
        
        int high = low + k;
        int ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    private boolean canAchieve(int[] arr, int k, int w, int target) {
        int n = arr.length;
        long[] diff = new long[n + 1];
        long added = 0;
        long used = 0;
        
        for (int i = 0; i < n; i++) {
            added += diff[i];
            
            long currentHeight = arr[i] + added;
            
            if (currentHeight < target) {
                long need = target - currentHeight;
                used += need;
                
                if (used > k) return false;
                
                added += need;
                if (i + w < diff.length)
                    diff[i + w] -= need;
            }
        }
        
        return true;
    }
}
