class Solution {
    public int minTime(int[] arr, int k) {
        int n = arr.length;
        
        long low = 0, high = 0;
        
        // Find max element and total sum
        for (int i = 0; i < n; i++) {
            low = Math.max(low, arr[i]);
            high += arr[i];
        }
        
        long result = high;
        
        while (low <= high) {
            long mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;  // try smaller maximum time
            } else {
                low = mid + 1;   // increase allowed time
            }
        }
        
        return (int) result;
    }
    
    private boolean isPossible(int[] arr, int k, long maxTime) {
        int painters = 1;
        long currentTime = 0;
        
        for (int length : arr) {
            if (currentTime + length <= maxTime) {
                currentTime += length;
            } else {
                painters++;
                currentTime = length;
                
                if (painters > k) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
