
class Solution {
    public int longestCommonSum(int[] a1, int[] a2) {
        int n = a1.length;

        // Map to store first occurrence of a particular sum
        HashMap<Integer, Integer> map = new HashMap<>();

        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            // Compute the current diff value
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            if (prefixSum == 0) {
                maxLen = i + 1;
            }

            if (map.containsKey(prefixSum)) {
                // If this prefix sum was seen before, update maxLen
                maxLen = Math.max(maxLen, i - map.get(prefixSum));
            } else {
                // Store the first occurrence of this prefix sum
                map.put(prefixSum, i);
            }
        }

        return maxLen;
    }
}
