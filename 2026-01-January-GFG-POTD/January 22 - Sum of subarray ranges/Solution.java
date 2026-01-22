class Solution {
    public int subarrayRanges(int[] arr) {
        int n = arr.length;
        long sumMin = 0, sumMax = 0;

        // Sum of subarray minimums
        sumMin = getSum(arr, true);

        // Sum of subarray maximums
        sumMax = getSum(arr, false);

        return (int)(sumMax - sumMin);
    }

    private long getSum(int[] arr, boolean isMin) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];

        java.util.Stack<Integer> stack = new java.util.Stack<>();

        // Previous smaller/greater
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() &&
                  (isMin ? arr[stack.peek()] > arr[i]
                         : arr[stack.peek()] < arr[i])) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? i + 1 : i - stack.peek();
            stack.push(i);
        }

        stack.clear();

        // Next smaller/greater
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() &&
                  (isMin ? arr[stack.peek()] >= arr[i]
                         : arr[stack.peek()] <= arr[i])) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? n - i : stack.peek() - i;
            stack.push(i);
        }

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long) arr[i] * left[i] * right[i];
        }

        return sum;
    }
}
