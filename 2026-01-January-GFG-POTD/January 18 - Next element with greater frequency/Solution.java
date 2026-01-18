class Solution {
    public ArrayList<Integer> nextFreqGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> result = new ArrayList<>();
        
        // Step 1: Frequency map
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        // Step 2: Initialize result with -1
        for (int i = 0; i < n; i++) {
            result.add(-1);
        }
        
        // Step 3: Stack to store indices
        Stack<Integer> stack = new Stack<>();
        
        // Step 4: Traverse array
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() &&
                   freq.get(arr[i]) > freq.get(arr[stack.peek()])) {
                result.set(stack.pop(), arr[i]);
            }
            stack.push(i);
        }
        
        return result;
    }
}
