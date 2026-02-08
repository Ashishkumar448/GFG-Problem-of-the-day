class Solution {
    int maxProduct(int[] arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int globalMax = arr[0];

        for (int i = 1; i < arr.length; i++) {
            int curr = arr[i];

            // If current element is negative, swap max and min
            if (curr < 0) {
                int temp = maxEndingHere;
                maxEndingHere = minEndingHere;
                minEndingHere = temp;
            }

            maxEndingHere = Math.max(curr, maxEndingHere * curr);
            minEndingHere = Math.min(curr, minEndingHere * curr);

            globalMax = Math.max(globalMax, maxEndingHere);
        }

        return globalMax;
    }
}
