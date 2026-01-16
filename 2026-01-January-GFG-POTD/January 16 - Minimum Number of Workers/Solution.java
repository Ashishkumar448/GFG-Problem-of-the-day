class Solution {
    public int minMen(int arr[]) {
        int n = arr.length;
        List<int[]> intervals = new ArrayList<>();

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int left = Math.max(0, i - arr[i]);
                int right = Math.min(n - 1, i + arr[i]);
                intervals.add(new int[]{left, right});
            }
        }

        // Sort intervals
        intervals.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return b[1] - a[1];
        });

        int workers = 0;
        int curr = 0;
        int i = 0;

        // Greedy coverage
        while (curr < n) {
            int farthest = curr;

            while (i < intervals.size() && intervals.get(i)[0] <= curr) {
                farthest = Math.max(farthest, intervals.get(i)[1] + 1);
                i++;
            }

            if (farthest == curr) {
                return -1; // cannot extend coverage
            }

            workers++;
            curr = farthest;
        }

        return workers;
    }
}
