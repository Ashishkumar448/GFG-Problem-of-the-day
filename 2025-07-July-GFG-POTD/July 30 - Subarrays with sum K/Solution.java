class Solution {
    public int cntSubarrays(int[] arr, int k) {
        // Map to store frequency of prefix sums
        HashMap<Integer, Integer> prefixSumCount = new HashMap<>();
        int count = 0;
        int prefixSum = 0;

        // Initialize with sum 0 to handle subarrays starting from index 0
        prefixSumCount.put(0, 1);

        for (int num : arr) {
            prefixSum += num;

            // Check if there exists a prefix sum that fulfills the condition
            if (prefixSumCount.containsKey(prefixSum - k)) {
                count += prefixSumCount.get(prefixSum - k);
            }

            // Add/update the prefix sum count
            prefixSumCount.put(prefixSum, prefixSumCount.getOrDefault(prefixSum, 0) + 1);
        }

        return count;
    }
}
