class Solution {
     public int maxPeople(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];

        Stack<int[]> stack = new Stack<>();

        // LEFT VISIBILITY
        for (int i = 0; i < n; i++) {
            int count = 0;

            while (!stack.isEmpty() && stack.peek()[0] < arr[i]) {
                count += stack.pop()[1];
            }

            left[i] = count;
            stack.push(new int[]{arr[i], count + 1});
        }

        stack.clear();

        // RIGHT VISIBILITY
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;

            while (!stack.isEmpty() && stack.peek()[0] < arr[i]) {
                count += stack.pop()[1];
            }

            right[i] = count;
            stack.push(new int[]{arr[i], count + 1});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, left[i] + right[i] + 1);
        }

        return ans;
    }
}
