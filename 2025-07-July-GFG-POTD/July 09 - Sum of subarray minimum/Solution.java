class Solution {
    public int sumSubMins(int[] arr) {
        int MOD = 1_000_000_007;
        int n = arr.length;

        int[] prevLess = new int[n];
        int[] nextLess = new int[n];

        Stack<Integer> stack = new Stack<>();

        // Compute previous less
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }
            prevLess[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        stack.clear();

        // Compute next less
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            nextLess[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        long sum = 0;
        for (int i = 0; i < n; ++i) {
            long left = i - prevLess[i];
            long right = nextLess[i] - i;
            sum = (sum + arr[i] * left * right) % MOD;
        }

        return (int)sum;
    }
}
