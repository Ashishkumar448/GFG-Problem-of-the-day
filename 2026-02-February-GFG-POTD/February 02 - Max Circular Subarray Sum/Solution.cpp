class Solution {
public:
    int maxCircularSum(int arr[], int n) {
        int totalSum = arr[0];

        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];

        int minEndingHere = arr[0];
        int minSoFar = arr[0];

        for (int i = 1; i < n; i++) {
            int x = arr[i];

            // Kadane for max subarray sum
            maxEndingHere = max(x, maxEndingHere + x);
            maxSoFar = max(maxSoFar, maxEndingHere);

            // Kadane for min subarray sum
            minEndingHere = min(x, minEndingHere + x);
            minSoFar = min(minSoFar, minEndingHere);

            totalSum += x;
        }

        // If all elements are negative
        if (maxSoFar < 0)
            return maxSoFar;

        // Maximum of wrapping and non-wrapping
        return max(maxSoFar, totalSum - minSoFar);
    }
};
