class Solution {
    public int totalElements(int[] arr) {
        int left = 0;
        int maxLength = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int right = 0; right < arr.length; right++) {
            // Add current element
            map.put(arr[right], map.getOrDefault(arr[right], 0) + 1);
            
            // Shrink window if more than 2 distinct elements
            while (map.size() > 2) {
                map.put(arr[left], map.get(arr[left]) - 1);
                
                if (map.get(arr[left]) == 0) {
                    map.remove(arr[left]);
                }
                
                left++;
            }
            
            // Update maximum length
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}
