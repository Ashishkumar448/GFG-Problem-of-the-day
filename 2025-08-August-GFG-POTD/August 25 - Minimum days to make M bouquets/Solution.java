class Solution {
    public int minDaysBloom(int[] arr, int k, int m) {
        int n = arr.length;
        
        // If not enough flowers to form m bouquets
        if ((long) m * k > n) return -1;
        
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;
        for (int day : arr) {
            left = Math.min(left, day);
            right = Math.max(right, day);
        }
        
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                right = mid - 1;  // try smaller day
            } else {
                left = mid + 1;  // need more days
            }
        }
        return ans;
    }
    
    private boolean canMake(int[] arr, int k, int m, int day) {
        int count = 0, bouquets = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0; // reset streak
            }
            if (bouquets >= m) return true;
        }
        return false;
    }
}
