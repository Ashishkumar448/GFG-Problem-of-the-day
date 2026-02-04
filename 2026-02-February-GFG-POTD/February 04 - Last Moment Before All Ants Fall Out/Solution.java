class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int lastTime = 0;

        // Ants moving to the left
        for (int pos : left) {
            lastTime = Math.max(lastTime, pos);
        }

        // Ants moving to the right
        for (int pos : right) {
            lastTime = Math.max(lastTime, n - pos);
        }

        return lastTime;
    }
}
