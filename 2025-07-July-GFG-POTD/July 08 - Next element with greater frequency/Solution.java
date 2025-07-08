class Solution {
    public ArrayList<Integer> findGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        Map<Integer, Integer> freqMap = new HashMap<>();

        // Step 1: Count frequencies
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            // Pop all elements from stack that have freq <= curr's freq
            while (!stack.isEmpty() && freqMap.get(stack.peek()) <= freqMap.get(curr)) {
                stack.pop();
            }

            // If stack is empty, no greater frequency element
            if (stack.isEmpty()) {
                res.add(-1);
            } else {
                res.add(stack.peek());
            }

            // Push current element to stack
            stack.push(curr);
        }

        // Reverse the result as we traversed from right to left
        Collections.reverse(res);
        return res;
    }
}
