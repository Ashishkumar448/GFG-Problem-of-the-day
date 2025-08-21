class Solution {
    public int maxMinDiff(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int low = 0, high = arr[n - 1] - arr[0], ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(arr, k, mid)) {
                ans = mid;     // mid is possible, try for larger
                low = mid + 1;
            } else {
                high = mid - 1; // too large, reduce
            }
        }
        return ans;
    }

    private boolean canPlace(int[] arr, int k, int dist) {
        int count = 1;  // pick first element
        int last = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
}
