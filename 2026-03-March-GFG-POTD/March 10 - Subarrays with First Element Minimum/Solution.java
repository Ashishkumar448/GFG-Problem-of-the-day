class Solution {
    public int countSubarrays(int[] arr) {
        int n = arr.length;
        Stack<Integer> stack = new Stack<>();
        long count = 0;

        for (int i = n - 1; i >= 0; i--) {
            
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }

            int nextSmaller = stack.isEmpty() ? n : stack.peek();
            count += nextSmaller - i;

            stack.push(i);
        }

        return (int)count;
    }
}
