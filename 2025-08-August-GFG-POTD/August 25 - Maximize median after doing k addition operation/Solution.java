class Solution {

    // check if we can make the median at least
    // 'target' using at most 'k' operations
    public boolean isPossible(int[] arr, int target, int k) {
        int n = arr.length;

        if (n % 2 == 1) {
            // for odd-sized array, consider elements from
            // middle to end
            for (int i = n / 2; i < n; ++i) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) break;
            }
        } else {
            // for even-sized array, handle two middle
            // elements separately
            if (arr[n / 2] <= target) {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            } else {
                k -= (2 * target - (arr[n / 2] + arr[n / 2 - 1]));
            }
            // process remaining elements to the right
            for (int i = n / 2 + 1; i < n; ++i) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) break;
            }
        }

        return k >= 0;
    }

    public int maximizeMedian(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);

        // compute initial median floor if even length
        int iniMedian = arr[n / 2];
        if (n % 2 == 0) {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }

        int low = iniMedian, high = iniMedian + k;
        int bestMedian = iniMedian;

        // binary search to find maximum
        // achievable median
        while (low <= high) {
            int mid = (low + high) / 2;

            if (isPossible(arr, mid, k)) {
                bestMedian = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bestMedian;
    }
}
