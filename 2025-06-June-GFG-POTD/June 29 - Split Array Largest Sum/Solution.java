class Solution {
     public int splitArray(int[] arr, int k) {
        int low = 0, high = 0;
        for (int num : arr) {
            low = Math.max(low, num); // the minimum possible answer
            high += num; // the maximum possible answer
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canSplit(arr, k, mid)) {
                high = mid; // try for smaller max sum
            } else {
                low = mid + 1; // need larger max sum
            }
        }

        return low;
    }

    // Helper function to check if we can split the array with max sum <= maxSum
    private boolean canSplit(int[] arr, int k, int maxSum) {
        int currentSum = 0;
        int splits = 1;

        for (int num : arr) {
            if (currentSum + num > maxSum) {
                // Need to split here
                splits++;
                currentSum = num;
                if (splits > k) return false;
            } else {
                currentSum += num;
            }
        }

        return true;
    }
};
