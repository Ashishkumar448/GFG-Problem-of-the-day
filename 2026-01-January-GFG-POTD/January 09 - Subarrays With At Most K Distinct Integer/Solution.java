class Solution {
    public int countAtMostK(int arr[], int k) {
        if (k == 0) return 0;
        
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        long count = 0;  // use long internally to avoid overflow
        
        for (int right = 0; right < arr.length; right++) {
            freq.put(arr[right], freq.getOrDefault(arr[right], 0) + 1);
            
            // shrink window until distinct <= k
            while (freq.size() > k) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0) {
                    freq.remove(arr[left]);
                }
                left++;
            }
            
            // all subarrays ending at right with start >= left are valid
            count += (right - left + 1);
        }
        
        return (int) count;
    }
}
