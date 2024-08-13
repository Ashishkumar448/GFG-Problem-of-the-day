class Solution {
    long floorSqrt(long n) {
        if (n == 0 || n == 1) {
            return n;
        }
        
        long left = 1, right = n, result = 0;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long midSquared = mid * mid;
            
            if (midSquared == n) {
                return mid;
            }
            if (midSquared < n) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
}
