class Solution {
    public ArrayList<String> graycode(int n) {
        ArrayList<String> result = new ArrayList<>();
        
        // Base case
        result.add("0");
        if (n == 1) {
            result.add("1");
            return result;
        }
        
        result.add("1");
        
        // Build from 2 to n
        for (int i = 2; i <= n; i++) {
            int size = result.size();
            
            // Step 1: Add reversed elements with '1' prefix
            for (int j = size - 1; j >= 0; j--) {
                result.add(result.get(j));
            }
            
            // Step 2: Add '0' prefix to first half
            for (int j = 0; j < size; j++) {
                result.set(j, "0" + result.get(j));
            }
            
            // Step 3: Add '1' prefix to second half
            for (int j = size; j < result.size(); j++) {
                result.set(j, "1" + result.get(j));
            }
        }
        
        return result;
    }
}
