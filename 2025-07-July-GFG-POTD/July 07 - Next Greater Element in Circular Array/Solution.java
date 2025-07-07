class Solution {
   public ArrayList<Integer> nextLargerElement(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stack = new Stack<>();

        // Traverse the array twice for circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
            // Maintain decreasing stack
            while (!stack.isEmpty() && arr[stack.peek()] <= arr[index]) {
                stack.pop();
            }
            // Only fill result in the first pass
            if (i < n) {
                if (!stack.isEmpty()) {
                    res.set(index, arr[stack.peek()]);
                }
            }
            stack.push(index);
        }
        return res;
    }
}
