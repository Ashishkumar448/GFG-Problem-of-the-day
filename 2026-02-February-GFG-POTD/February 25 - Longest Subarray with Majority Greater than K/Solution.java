class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            // Convert to +1 / -1
            if (arr[i] > k) {
                prefixSum += 1;
            } else {
                prefixSum -= 1;
            }
            
            // If prefix sum > 0, whole array till i is valid
            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                // Check if there exists a prefixSum - 1
                if (map.containsKey(prefixSum - 1)) {
                    maxLen = Math.max(maxLen, i - map.get(prefixSum - 1));
                }
            }
            
            // Store first occurrence only
            if (!map.containsKey(prefixSum)) {
                map.put(prefixSum, i);
            }
        }
        
        return maxLen;
    }
}
