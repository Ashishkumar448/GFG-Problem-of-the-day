class Solution {
   public int minDifference(String[] arr) {
        int n = arr.length;
        int[] seconds = new int[n];
        
        // Convert time strings to seconds
        for (int i = 0; i < n; i++) {
            String[] parts = arr[i].split(":");
            int h = Integer.parseInt(parts[0]);
            int m = Integer.parseInt(parts[1]);
            int s = Integer.parseInt(parts[2]);
            seconds[i] = h * 3600 + m * 60 + s;
        }
        
        // Sort the seconds array
        Arrays.sort(seconds);
        
        int minDiff = Integer.MAX_VALUE;
        
        // Compute difference between adjacent times
        for (int i = 1; i < n; i++) {
            minDiff = Math.min(minDiff, seconds[i] - seconds[i - 1]);
        }
        
        // Handle wrap-around at midnight
        int dayInSeconds = 24 * 3600;
        int wrapAroundDiff = dayInSeconds - seconds[n - 1] + seconds[0];
        minDiff = Math.min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
}
