class Solution {
    public int minimumCoins(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;

        // Compute prefix sums
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        int minCoins = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];
            int maxAllowed = minVal + k;

            // Binary search: last index j such that arr[j] <= maxAllowed
            int j = upperBound(arr, maxAllowed) - 1;

            // Remove all coins before i
            long leftRemove = prefixSum[i];

            // Remove excess coins after j
            long totalRightCoins = prefixSum[n] - prefixSum[j + 1];
            int countRight = n - j - 1;
            long maxAllowedTotal = (long) (countRight) * maxAllowed;
            long rightRemove = totalRightCoins - maxAllowedTotal;

            long totalRemove = leftRemove + rightRemove;
            minCoins = (int) Math.min(minCoins, totalRemove);
        }

        return minCoins;
    }

    // Find first index where arr[i] > key
    private int upperBound(int[] arr, int key) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
