class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        
        // If the first element is 0, we can't move anywhere
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 0;
        int farthest = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = Math.max(farthest, i + arr[i]);

            // If we reach the end of the current jump range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // If we cannot move forward
                if (currentEnd <= i) return -1;

                // If we can reach or cross the last index
                if (currentEnd >= n - 1) return jumps;
            }
        }
        
        return -1;
    }
}
