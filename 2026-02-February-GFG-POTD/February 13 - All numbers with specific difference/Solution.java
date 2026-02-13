class Solution {
    
    private int digitSum(long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    public int getCount(int n, int d) {
        
        long low = 1, high = n;
        long ans = -1;
        
        while (low <= high) {
            long mid = low + (high - low) / 2;
            
            if (mid - digitSum(mid) >= d) {
                ans = mid;
                high = mid - 1; // try to find smaller valid
            } else {
                low = mid + 1;
            }
        }
        
        if (ans == -1) return 0;
        
        return (int)(n - ans + 1);
    }
}
