class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            // Swap until the current element is in the correct position
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                int correctIndex = arr[i] - 1;
                // Swap arr[i] with arr[correctIndex]
                int temp = arr[i];
                arr[i] = arr[correctIndex];
                arr[correctIndex] = temp;
            }
        }

        // After placement, find the first place where index + 1 != value
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all values are in place
        return n + 1;
    }
}
