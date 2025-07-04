class Solution {
   public int countAtMostK(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> freqMap = new HashMap<>();
        int start = 0, result = 0;

        for (int end = 0; end < n; end++) {
            // Include arr[end] in the window
            freqMap.put(arr[end], freqMap.getOrDefault(arr[end], 0) + 1);

            // If distinct elements > k, shrink from start
            while (freqMap.size() > k) {
                freqMap.put(arr[start], freqMap.get(arr[start]) - 1);
                if (freqMap.get(arr[start]) == 0) {
                    freqMap.remove(arr[start]);
                }
                start++;
            }

            // All subarrays ending at `end` with at most k distinct elements
            result += (end - start + 1);
        }

        return result;
    }
}
