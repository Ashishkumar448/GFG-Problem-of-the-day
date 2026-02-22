class Solution {
    public long subarrayXor(int arr[], int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        long count = 0;
        int xor = 0;
        
        // Base case: prefix XOR 0 appears once
        map.put(0, 1);
        
        for (int num : arr) {
            xor ^= num;
            
            // If (xor ^ k) exists, add its frequency
            if (map.containsKey(xor ^ k)) {
                count += map.get(xor ^ k);
            }
            
            // Update frequency of current prefix xor
            map.put(xor, map.getOrDefault(xor, 0) + 1);
        }
        
        return count;
    }
}
