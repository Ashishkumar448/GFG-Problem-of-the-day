class Solution {
public:
    // Find pivot index (minimum element)
    int findPivot(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    // Count elements <= x in sorted range [l..r]
    int countLE(vector<int>& arr, int l, int r, int x) {
        if (l > r) return 0;

        int low = l, high = r;
        int res = l - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res - l + 1;
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = findPivot(arr);

        int count = 0;
        count += countLE(arr, pivot, n - 1, x);
        count += countLE(arr, 0, pivot - 1, x);

        return count;
    }
};
