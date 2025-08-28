class Solution {
     public int maxOnes(int arr[], int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;

        while (right < arr.length) {
            // Expand the window
            if (arr[right] == 0) {
                zeroCount++;
            }

            // If more than k zeros, shrink window from left
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Update maximum window size
            maxLen = Math.max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
}
