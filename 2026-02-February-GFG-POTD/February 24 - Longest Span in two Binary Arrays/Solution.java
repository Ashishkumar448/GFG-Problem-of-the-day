class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        int n = a1.length;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        int prefix1 = 0, prefix2 = 0;
        int maxLen = 0;
        
        // Important: diff 0 at index -1
        map.put(0, -1);
        
        for (int i = 0; i < n; i++) {
            prefix1 += a1[i];
            prefix2 += a2[i];
            
            int diff = prefix1 - prefix2;
            
            if (map.containsKey(diff)) {
                int prevIndex = map.get(diff);
                maxLen = Math.max(maxLen, i - prevIndex);
            } else {
                // Store first occurrence only
                map.put(diff, i);
            }
        }
        
        return maxLen;
    }
}
