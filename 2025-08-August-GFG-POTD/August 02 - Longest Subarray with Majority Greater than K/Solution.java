class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        int[] transformed = new int[n];

        // Step 1: Transform the array
        for (int i = 0; i < n; i++) {
            transformed[i] = (arr[i] > k) ? 1 : -1;
        }

        // Step 2: Use prefix sum and hashmap
        HashMap<Integer, Integer> firstIndex = new HashMap<>();
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += transformed[i];

            // Case 1: If prefixSum is positive till this point
            if (prefixSum > 0) {
                maxLen = i + 1;
            }
            // Case 2: If prefixSum is seen before, try to find a longer subarray
            else {
                if (!firstIndex.containsKey(prefixSum)) {
                    firstIndex.put(prefixSum, i);
                }

                // Check if (prefixSum - 1) was seen before
                if (firstIndex.containsKey(prefixSum - 1)) {
                    int prevIndex = firstIndex.get(prefixSum - 1);
                    maxLen = Math.max(maxLen, i - prevIndex);
                }
            }
        }

        return maxLen;
    }
}
