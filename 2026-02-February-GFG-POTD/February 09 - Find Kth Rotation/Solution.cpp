class Solution {
public:
    int findKRotation(int arr[], int n) {
        int low = 0, high = n - 1;

        while (low <= high) {
            // If subarray is already sorted
            if (arr[low] <= arr[high]) {
                return low;
            }

            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            // Check if mid is minimum
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return mid;
            }

            // Decide which half to search
            if (arr[mid] >= arr[low]) {
                // Left half sorted → go right
                low = mid + 1;
            } else {
                // Right half sorted → go left
                high = mid - 1;
            }
        }

        return 0;
    }
};
