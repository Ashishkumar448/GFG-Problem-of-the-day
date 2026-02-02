class Solution {
    public int maxCircularSum(int arr[]) {
        int totalSum = 0;

        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];

        int minEndingHere = arr[0];
        int minSoFar = arr[0];

        totalSum = arr[0];

        for (int i = 1; i < arr.length; i++) {
            int x = arr[i];

            // Kadane for max subarray sum
            maxEndingHere = Math.max(x, maxEndingHere + x);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);

            // Kadane for min subarray sum
            minEndingHere = Math.min(x, minEndingHere + x);
            minSoFar = Math.min(minSoFar, minEndingHere);

            totalSum += x;
        }

        // If all elements are negative
        if (maxSoFar < 0) {
            return maxSoFar;
        }

        // Maximum of wrapping and non-wrapping
        return Math.max(maxSoFar, totalSum - minSoFar);
    }
}
