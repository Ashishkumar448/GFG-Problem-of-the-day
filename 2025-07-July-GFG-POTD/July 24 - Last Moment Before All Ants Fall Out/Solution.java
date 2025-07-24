class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int maxTime = 0;
        
        // Time for ants moving left: distance to 0
        for (int pos : left) {
            maxTime = Math.max(maxTime, pos);
        }
        
        // Time for ants moving right: distance to n
        for (int pos : right) {
            maxTime = Math.max(maxTime, n - pos);
        }
        
        return maxTime;
    }
}
